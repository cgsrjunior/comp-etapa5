#include <iostream>
#include <algorithm>
#include <string>
#include "iloc.hh"

//Regra pra gerar as strings das instruções
static const char *instruct_to_string[] ={
        "nop",
        "add",
        "sub",
        "mult",
        "div",
        "addI",
        "subI",
        "rsubI",
        "multI",
        "divI",
        "rdivI",
        "lshift",
        "lshiftI",
        "rshift",
        "rshiftI",
        "and",
        "andI",
        "or",
        "orI",
        "xor",
        "xorI",
        "loadI",
        "load",
        "loadAI",
        "loadA0",
        "cload",
        "cloadAI",
        "cloadA0",
        "store",
        "storeAI",
        "storeAO",
        "cstore",
        "cstoreAI",
        "cstoreAO",
        "i2i",
        "c2c",
        "c2i",
        "i2c",
        // Controle de fluxo
        "jumpI",
        "jump",
        "cbr",
        "cmp_LT",
        "cmp_LE",
        "cmp_EQ",
        "cmp_GE",
        "cmp_GT",
        "cmp_NE"
};


//TODO - Func pra gravar uma instrução
//TODO - Func pra gerar o output
