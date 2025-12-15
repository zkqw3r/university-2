#include <Python.h>
#include <ctime>
#include <stdio.h>

static PyObject* find_min_fast(PyObject* self, PyObject* args) {
	PyObject* listObj;
	long min_val;
	long temp_val;
	int size;
	int i;

	if (!PyArg_ParseTuple(args, "O", &listObj)) {
		return NULL;
	}

	size = PyList_Size(listObj);
	if (size == 0) {
		PyErr_SetString(PyExc_ValueError, "List is empty");
		return NULL;
	}

	min_val = PyLong_AsLong(PyList_GetItem(listObj, 0));

	clock_t st = clock();
	for (i = 1; i < size; i++) {
		temp_val = PyLong_AsLong(PyList_GetItem(listObj, i));
		if (temp_val < min_val) {
			min_val = temp_val;
		}
	}
	clock_t end = clock();
	double time = ((double)(end - st)) / CLOCKS_PER_SEC;

	printf("C++ time: %.10f s\n", time);
	return Py_BuildValue("l", min_val);
}

static PyMethodDef MyMethods[] = {
	{"find_min_fast", find_min_fast, METH_VARARGS, "Find minimum in list"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
	PyModuleDef_HEAD_INIT,
	"SuperFastFinder",
	"Fast finder minimum",
	-1,
	MyMethods
};

PyMODINIT_FUNC PyInit_SuperFastFinder(void) {
	return PyModule_Create(&mymodule);
}