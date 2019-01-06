#include "/usr/include/python3.6m/Python.h"
#include <string.h>

static PyObject* message(PyObject* self, PyObject* args) {
    FILE* file_out;
    char* fromPython;
    char result[1024];

    file_out = fopen("output_file", "w");

    if (!PyArg_Parse(args, "(s)", &fromPython)) { // Python -> C 
        return NULL;
    } else {
        fputs("This is Python-C integration, bitch!", file_out);
        strcpy(result, "Hello, "); 
        strcat(result, fromPython);
        return Py_BuildValue("s", result); // Return to Python C -> Python 
    }
    fclose(file_out);
}

// Methods registration table
static PyMethodDef hello_methods[] = {
    // function name, function address, format, function description
    {"message", message, METH_VARARGS, "Function description"},
    {NULL, NULL, 0, NULL}   // This is how the end of the table is marked
};

// module definition structure
static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,  // #define PyModuleDef_HEAD_INIT { PyObject_HEAD_INIT(NULL) NULL, 0, NULL, }
    "hello",                // Module name
    "Module description",   // Module descr.
    -1,                     // Structure size for every instance, -1 means global variable. Whatever it supposed to mean.
    hello_methods           // Reference to the methods table
};

PyMODINIT_FUNC PyInit_hello() { // Called due to import in Python. The name can't be changed, when dynamic lib is being used 
    return PyModule_Create(&hellomodule);
}
