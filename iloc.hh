#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

using label_type = int;
using reg_type = int;

//Tipos de instrução em ILOC
enum Instruct {
    NOP,
    ADD,
    SUB,
    MULT,
    DIV,
    ADD_I,
    SUB_I,
    RSUB_I,
    MULT_I,
    DIV_I,
    RDIV_I,
    LSHIFT,
    LSHIFT_I,
    RSHIFT,
    RSHIFT_I,
    AND,
    AND_I,
    OR,
    OR_I,
    XOR,
    XOR_I,
    LOAD_I,
    LOAD,
    LOAD_AI,
    LOAD_A0,
    CLOAD,
    CLOAD_AI,
    CLOAD_A0,
    STORE,
    STORE_AI,
    STORE_AO,
    CSTORE,
    CSTORE_AI,
    CSTORE_AO,
    I2I,
    C2C,
    C2I,
    I2C,
    // Controle de fluxo
    JUMP_I,
    JUMP,
    CBR,
    CMP_LT,
    CMP_LE,
    CMP_EQ,
    CMP_GE,
    CMP_GT,
    CMP_NE
};


struct Cod_ILOC{
    //Listing all registers
    const reg_type NO_REG = 0;
    const reg_type RBSS = 1;
    const reg_type RFP = 2;
    const reg_type RSP = 3;
    const reg_type RPC = 4;
    reg_type counter = 5;

    const reg_type ADDR_DESLOC = -4;
    const reg_type VALUE_DESLOC = -8;

    inline reg_type get_new_register() { return counter++; }


    const label_type NO_LABEL = 0;
    label_type label_id = 1;

    inline label_type get_new_label() { return label_id++; }    
    
};

struct Command{
    // INST [r1|c] [r2|c] => <rd|L> [L]
    // inst  op1    op2       op3   op4
    label_type label;
    Instruct inst;
    reg_type op1;
    reg_type op2;
    reg_type op3;
    reg_type op4;

    //Initialize operators
    Command(label_type label, Instruct inst);
    //Initialize unitilized operator on 0 
    Command(Instruct inst, reg_type op1, reg_type op2, reg_type op3, reg_type op4);
    //Idea: form a string on the following format indicate above on first line
    string formatstring();
};

struct ILOC_struct{
    reg_type temp;
    label_type flag_true;
    label_type flag_false;
};

/*
     ______________________
    |      valor_ret       |
    |       addr_ret       |
    |======================| -> Base da pilha (RFP)
    |        param0        |
    |        param1        |
    |          ...         |
    |        paramN        |
    |- - - - - - - - - - - |
    |         var0         |
    |         var1         |
    |          ...         |
    |         varN         |
    |- - - - - - - - - - - |
    |    vinc_estatico     |
    |    vinc_dinamico     |
    |     


*/
