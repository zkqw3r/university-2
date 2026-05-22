import math
import time
import heapq
import matplotlib.pyplot as plt
import xml.etree.ElementTree as ET
from typing import Dict, List, Tuple
from matplotlib.collections import LineCollection


def dijkstra(graph: Dict[Tuple[float, float], List[Tuple[Tuple[float, float], float]]],
             start: Tuple[float, float],
             end: Tuple[float, float]) -> Tuple[List[Tuple[float, float]], float, List[str]]:

    # Приоритетная очередь для хранения (расстояние, узел)
    queue = [(0.0, start)]
    
    # Словарь для хранения кратчайшего расстояния до каждого узла и предыдущего узла
    shortest_paths = {start: (0.0, None)}
    
    # Множество посещённых узлов
    visited = set()

    while queue:
        curr_dist, curr_node = heapq.heappop(queue)
        if curr_node == end:
            break
        if curr_node in visited:
            continue
        visited.add(curr_node)

        for neighbor, weight in graph.get(curr_node, []):
            distance = curr_dist + weight
            
            if neighbor not in shortest_paths or distance < shortest_paths[neighbor][0]:
                shortest_paths[neighbor] = (distance, curr_node)
                heapq.heappush(queue, (distance, neighbor))
    path = []
    current = end
    if current not in shortest_paths:
        return [], float('inf'), []

    while current is not None:
        path.append(current)
        current = shortest_paths[current][1]
    path.reverse()
    
    # Общее расстояние от начала до конца
    total_distance = shortest_paths[end][0]

    return path, total_distance, []


def haversine(coord1: Tuple[float, float], coord2: Tuple[float, float]) -> float:
    """
    Вычисляет расстояние между двумя точками на поверхности Земли (в километрах)
    """
    lon1, lat1 = coord1
    lon2, lat2 = coord2
    R = 6371  # Радиус Земли в км

    phi1, phi2 = math.radians(lat1), math.radians(lat2)
    dphi = math.radians(lat2 - lat1)
    dlambda = math.radians(lon2 - lon1)

    a = math.sin(dphi/2)**2 + math.cos(phi1)*math.cos(phi2)*math.sin(dlambda/2)**2
    return 2 * R * math.atan2(math.sqrt(a), math.sqrt(1 - a))


def build_graph(edges: List[Tuple[Tuple[float, float], Tuple[float, float], str]]) -> Dict[Tuple[float, float], List[Tuple[Tuple[float, float], float]]]:
    """
    Строит граф из рёбер
    """
    graph = {}
    for start, end, _ in edges:
        dist = haversine(start, end)
        graph.setdefault(start, []).append((end, dist))
        graph.setdefault(end, []).append((start, dist))  # если граф неориентированный
    return graph


def read_graphml(file_path: str) -> Tuple[Dict[str, Tuple[float, float]], List[Tuple[Tuple[float, float], Tuple[float, float], str]]]:
    """
    Читает GraphML файл и возвращает узлы и ребра с названиями улиц

    Args:
        file_path: путь к файлу .graphml

    Returns:
        Кортеж (nodes, edges), где:
        - nodes: словарь {node_id: (x, y)}
        - edges: список [((x1, y1), (x2, y2), название_улицы), ...]
    """
    tree = ET.parse(file_path)
    root = tree.getroot()
    ns = {'g': 'http://graphml.graphdrawing.org/xmlns'}

    nodes = {}
    for node in root.findall('.//g:node', ns):
        node_id = node.get('id')
        x, y = None, None
        for data in node.findall('.//g:data', ns):
            if data.get('key') == 'd4':  # x координата (обычно longitude)
                x = float(data.text)
            elif data.get('key') == 'd5':  # y координата (обычно latitude)
                y = float(data.text)
        if x is not None and y is not None:
            nodes[node_id] = (x, y)

    edges = []
    for edge in root.findall('.//g:edge', ns):
        source = edge.get('source')
        target = edge.get('target')
        street_name = None

        for data in edge.findall('.//g:data', ns):
            if data.get('key') == 'd15':  # название улицы
                street_name = data.text if data.text else None

        if source in nodes and target in nodes:
            edges.append((nodes[source], nodes[target], street_name))

    return nodes, edges


def find_street_index(edges: List[Tuple[Tuple[float, float], Tuple[float, float], str]], 
                    street_name_query: str) -> Tuple[int, str]:
    """
    Возвращает индекс (номер) и название улицы по заданному имени

    Args:
        edges: список рёбер с названиями улиц
        street_name_query: название улицы для поиска

    Returns:
        Кортеж (индекс, название_улицы), если найдено, иначе (-1, None)
    """
    for i, (_, _, name) in enumerate(edges):
        if name and name.lower() == street_name_query.lower():
            return i, name
    return -1, None


def visualize_path_with_network(nodes, edges, path, street_names=None, figsize=(20, 20)):
    """
    Визуализация всей дорожной сети + маршрута красным.
    Если передан список street_names, то названия улиц выводятся вдоль маршрута.
    """
    plt.figure(figsize=figsize)
    ax = plt.gca()

    # Все рёбра — серые
    all_lines = [(start, end) for start, end, _ in edges]
    lc = LineCollection(all_lines, linewidths=0.3, colors='gray', alpha=0.4)
    ax.add_collection(lc)

    # Путь — красный
    if path and len(path) > 1:
        path_lines = [(path[i], path[i+1]) for i in range(len(path)-1)]
        lc_path = LineCollection(path_lines, linewidths=2.0, colors='red', alpha=0.9)
        ax.add_collection(lc_path)

        # Отображаем названия улиц, если они заданы
        if street_names:
            for i in range(len(path)-1):
                mid_point = ((path[i][0] + path[i+1][0]) / 2, (path[i][1] + path[i+1][1]) / 2)
                if i < len(street_names) and street_names[i]:
                    plt.text(mid_point[0], mid_point[1], street_names[i],
                            fontsize=8, color='blue', ha='center')

    ax.autoscale()
    plt.axis('equal')
    plt.title('Кратчайший маршрут')
    plt.xlabel('Долгота')
    plt.ylabel('Широта')
    plt.grid(False)
    plt.tight_layout()
    plt.show()


def save_visualization(filename: str, dpi: int = 300) -> None:
    """
    Сохраняет текущую визуализацию в файл

    Args:
        filename: имя файла для сохранения
        dpi: разрешение изображения
    """
    plt.savefig(filename, dpi=dpi, bbox_inches='tight')
    plt.close()


def visualize_only_path(path, figsize=(10, 10)):
    """
    Визуализирует только маршрут (без остального графа)
    """
    if not path or len(path) < 2:
        print("Маршрут слишком короткий или отсутствует.")
        return

    plt.figure(figsize=figsize)
    ax = plt.gca()

    path_lines = [(path[i], path[i+1]) for i in range(len(path)-1)]
    lc_path = LineCollection(path_lines, linewidths=2.5, colors='red', alpha=0.9)
    ax.add_collection(lc_path)

    ax.autoscale()
    plt.axis('equal')
    plt.title("Кратчайший маршрут")
    plt.xlabel("Долгота")
    plt.ylabel("Широта")
    plt.grid(True)
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    nodes, edges = read_graphml("Лондон.graphml")
    print(f"Количество вершин {len(nodes)} ребер {len(edges)}")

    start_street_query = "The Drive"
    end_street_query = "Carlisle Place"

    start_index, start_street = find_street_index(edges, start_street_query)
    end_index, end_street = find_street_index(edges, end_street_query)

    if start_index == -1 or end_index == -1:
        print("Не удалось найти заданную улицу для начала или конца маршрута")
    else:
        print(start_street)
        print(end_street)
        
        start_node = edges[start_index][0]
        end_node = edges[end_index][1]
        graph = build_graph(edges)
        
        start_time = time.time()
        path, distance, street_names = dijkstra(graph, start_node, end_node)
        end_time = time.time()
        algorithm_time = end_time - start_time

        if not path:
            print("Путь не найден")
        else:
            print(f"Время работы: {algorithm_time:.6f} с")
            print(f"Длина пути {distance:.5f} км")

            visualize_path_with_network(nodes, edges, path, street_names)