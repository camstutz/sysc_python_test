/*!
 * @file testbench.hpp
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

#include <iostream>
#include <sstream>

#include "systemc.h"

#include "python_module_w.hpp"

/*!
 * @brief
 */
class testbench : public sc_module
{
public:

    // ----- Port Declarations -------------------------------------------------

    // ----- Local Channel Declarations ----------------------------------------
    sc_buffer<unsigned int> in_sig1;
    sc_buffer<unsigned int> in_sig2;
    sc_buffer<unsigned int> out_sig;

    // ----- Process Declarations ----------------------------------------------
    void generate_output();
    void print_input();

    // ----- Other Method Declarations -----------------------------------------

    // ----- Module Instantiations ---------------------------------------------
    python_module_w dut;

    // ----- Constructor -------------------------------------------------------
    /*!
     * Constructor:
     */
    testbench(sc_module_name _name);
    SC_HAS_PROCESS(testbench);

private:
};
