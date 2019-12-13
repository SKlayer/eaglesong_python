#include <Python.h>
#include "Eaglesong.h"


static PyObject *eaglesong_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    EaglesongHash(output,(uint8_t *)PyBytes_AsString((PyObject*) input), PyBytes_Size((PyObject*) input));
#else
    EaglesongHash(output,(uint8_t )PyString_AsString((PyObject*) input), PyBytes_Size((PyObject*) input));
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef EaglesongMethods[] = {
    { "hash", eaglesong_getpowhash, METH_VARARGS, "Returns the hash using eaglesong hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef EAGLESONGModule = {
    PyModuleDef_HEAD_INIT,
    "EaglesongHash",
    "...",
    -1,
    EaglesongMethods
};

PyMODINIT_FUNC PyInit_eaglesong_hash(void) {
    return PyModule_Create(&EAGLESONGModule);
}

#else

PyMODINIT_FUNC initeaglesong_hash(void) {
    (void) Py_InitModule("eaglesonghash", EaglesongMethods);
}
#endif
