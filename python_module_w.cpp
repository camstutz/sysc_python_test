/*!
 * @file python_module_w.cpp
 * @author Christian Amstutz
 * @date Oct 17, 2014
 */

/*
 *  Copyright (c) 2014 by Christian Amstutz
 */

#include "python_module_w.hpp"

// *****************************************************************************

// *****************************************************************************

/*!
 * @class python_module_w
 */

python_module_w::python_module_w(sc_module_name _name) :
        sc_module(_name),
        in1("in1"),
        in2("in2"),
        out("out")
{
    // ----- Creation and binding of signals -----------------------------------

    // ----- Process registration ----------------------------------------------
    SC_THREAD(pyFunction);
        sensitive << in1 << in2;

    // ----- Module variable initialization ------------------------------------

    // ----- Module instance / channel binding ---------------------------------

    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/amstutz/eclipse_workspace/sysc_python_test')");

    PyObject *pName, *pModule;

    pName = PyString_FromString("multiplier");
    PyErr_Print();

    pModule = PyImport_Import(pName);
    PyErr_Print();

    if (pModule != NULL) {
      pFunc = PyObject_GetAttrString(pModule, "multiplier");
      if (!(pFunc && PyCallable_Check(pFunc)))
      {
         PyErr_Print();
          std::cout << "Cannot find function 'multiplier'" << std::endl;
      }
            Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        std::cout << "Failed to load module 'multiplier'" << std::endl;
    }

    return;
}

// *****************************************************************************
python_module_w::~python_module_w()
{
    Py_XDECREF(pFunc);

    Py_Finalize();

    return;
}


// *****************************************************************************
void python_module_w::pyFunction()
{
    PyObject *pArgs, *pValue;

    while(1)
    {
         wait();

         pArgs = PyTuple_New(2);
         pValue = PyInt_FromLong(in1.read());
         PyTuple_SetItem(pArgs, 0, pValue);
         pValue = PyInt_FromLong(in2.read());
         PyTuple_SetItem(pArgs, 1, pValue);

         pValue = PyObject_CallObject(pFunc, pArgs);

         out.write(PyInt_AsLong(pValue));
         Py_DECREF(pArgs);
         Py_DECREF(pValue);


    }

}
