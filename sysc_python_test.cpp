/*!
 * @file sysc_python_test.cpp
 * @author Christian Amstutz
 * @date Oct 17, 2014
 *
 * @brief
 */

/*
 *  Copyright (c) 2014 by Christian Amstutz
 */

#include <systemc.h>
#include <iostream>
#include <string>

#include "testbench.hpp"

int sc_main(int argc, char *agv[])
{
    // ----- Set up tracing ----------------------------------------------------
    //sc_trace_file *trace_file;
    //trace_file = sc_create_vcd_trace_file("TT_TB_testbench");

    // ----- Channel declarations ----------------------------------------------

    // ----- Variable declarations ---------------------------------------------

    // ----- Module instance declarations --------------------------------------

    testbench tb1("tb1");

    // ----- Time unit / resolution setup --------------------------------------

    // ----- Start simulation --------------------------------------------------

    std::cout << std::endl << "Start test bench ..." << std::endl << std::endl;

    //sc_report_handler::set_actions (SC_ID_MORE_THAN_ONE_SIGNAL_DRIVER_, SC_DO_NOTHING);
    sc_set_time_resolution(1,SC_PS);
    sc_start(1500, SC_NS);

    //sc_close_vcd_trace_file(trace_file);

    std::cout << std::endl << "Test bench ended." << std::endl;

    return (0);
}
