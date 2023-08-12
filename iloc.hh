#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

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

//Using this to store the temp_values
//Need to check when we need to search on this list
struct List_Temp{
    string label_temp;
    int value;
};

struct Cod_ILOC{
    //Codigo de 3 endereços
    Instruct instruction;
    //Need to define a type to declare the ends
    string end1;
    string end2;
    string end3;
};

struct List_ILOC{
    //Lista de instruções ILOC
    vector<Cod_ILOC> list_inst;
    //TODO operation on the list

    //Setting instructions
    inline Cod_ILOC get_iloc_inst(int i){return this->list_inst[i];}
    inline void set_iloc_inst(int i, Cod_ILOC inst){this->list_inst[i]= inst;}
};

