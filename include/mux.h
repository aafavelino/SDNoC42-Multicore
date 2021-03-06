//
// Created by Adelino, Raul and Yuri on 02/11/18.
//

#ifndef _MUX_H_
#define _MUX_H_

#include <iostream>
#include "systemc.h"

SC_MODULE (mux){

	// Entradas do multiplexador.
	sc_in<sc_uint<32> > entrada_1, entrada_2, entrada_3, entrada_4;

	// Seletor da prota de entrada.
	sc_in<sc_uint<2> > seletor;

	// Chaveamento do multiplexador.
	sc_in<sc_uint<1> > enable;
	
	// Porta de saída de acordo com a entrada escolhida.
	sc_out<sc_uint<32> > saida;

	// Procedimento para selecionar a porta de entrada.
	void action();

	// Construtor padrão.
	SC_CTOR(mux): 
		entrada_1("entrada_1"), 
		entrada_2("entrada_2"), 
		entrada_3("entrada_3"), 
		entrada_4("entrada_4"), 
		seletor("seletor"),
		enable("enable"),
		saida("saida")
	{
		// O método action será sensível à todas as portas de entrada.
		SC_METHOD(action);
			sensitive << entrada_1;
			sensitive << entrada_2;
			sensitive << entrada_3;
			sensitive << entrada_4;
			sensitive << seletor;
			sensitive << enable;
	}	
};
#endif