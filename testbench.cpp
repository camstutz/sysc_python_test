/*!
 * @file testbench.cpp
 * @author Christian Amstutz
 * @date Oct 17, 2014
 */

/*
 *  Copyright (c) 2014 by Christian Amstutz
 */

#include "testbench.hpp"

// *****************************************************************************

// *****************************************************************************

/*!
 * @class testbench
 */

testbench::testbench(sc_module_name _name) :
        sc_module(_name),
        in_sig1("in_sig1"),
        in_sig2("in_sig2"),
        out_sig("out_sig"),
        dut("DUT")
{
    // ----- Creation and binding of signals -----------------------------------

    // ----- Process registration ----------------------------------------------
    SC_THREAD(generate_output);
    SC_THREAD(print_input);
        sensitive << out_sig;

    // ----- Module variable initialization ------------------------------------

    // ----- Module instance / channel binding ---------------------------------
    dut.in1(in_sig1);
    dut.in2(in_sig2);
    dut.out(out_sig);

    return;
}

// *****************************************************************************
void testbench::generate_output()
{
    in_sig1.write(1);
    in_sig2.write(1);

    wait(50,SC_NS);
    in_sig1.write(3);
    in_sig2.write(4);

    wait(100,SC_NS);
    in_sig1.write(1);

    std::cout << sc_time_stamp() << ": All input values sent" << std::endl;

    return;
}

// *****************************************************************************
void testbench::print_input()
{
    while(1)
    {
         wait();

         std::cout << sc_time_stamp() << ": Result - " << out_sig.read() << std::endl;
    }

}
