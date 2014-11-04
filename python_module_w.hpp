/*!
 * @file python_module_w.hpp
 * @author Christian Amstutz
 * @date Oct 17, 2014
 *
 * @brief
 *
 */

/*
 *  Copyright (c) 2014 by Christian Amstutz
 */

#pragma once

#include "Python.h"
#include "systemc.h"

/*!
 * @brief
 */
class python_module_w : public sc_module
{
public:

    PyObject *pFunc;

    // ----- Port Declarations -------------------------------------------------
    sc_in<unsigned int> in1;
    sc_in<unsigned int> in2;
    sc_out<unsigned int> out;

    // ----- Local Channel Declarations ----------------------------------------

    // ----- Process Declarations ----------------------------------------------
    void pyFunction();

    // ----- Other Method Declarations -----------------------------------------

    // ----- Module Instantiations ---------------------------------------------

    // ----- Constructor -------------------------------------------------------
    /*!
     * Constructor:
     */
    python_module_w(sc_module_name _name);
    SC_HAS_PROCESS(python_module_w);
    ~python_module_w();

private:
};
