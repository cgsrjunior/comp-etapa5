#include <iostream>
#include <algorithm>
#include <string>
#include "iloc.hh"

#define NO_REG 0;

using namespace std;

Command::Command(label_type label, Instruct inst){
        this->label = label;
        this->inst = inst;
}

//Only instruction and operands
Command::Command(Instruct inst, reg_type op1, reg_type op2, reg_type op3, reg_type op4){
        this->inst = inst;
        this->op1 = op1;
        this->op2 = op2;
        this->op3 = op3;
        this->op4 = op4;
}

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
        // Flux control
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

//Check if a register was inserted
bool register_inserted(reg_type key, vector<reg_type> list){
    if (find(list.begin(), list.end(), key) != list.end())
        return true;
    return false;
}

//Function to get register_name
string get_register_name(reg_type reg) {
    switch (reg){
    case 1:
        return "bss";
    case 2:
        return "fp";
    case 3:
        return "sp";
    case 4:
        return "pc";
    default:
        return to_string(reg);
    }
}



string Command::formatstring(){
        ostringstream buffer;
        // Usage of Reg/Const/Labels/x => Nulo 
        // for each instruct
        vector<reg_type> xxxx {0};
        vector<reg_type> RRRx {1, 2, 3, 4, 11, 13, 15, 17, 19, 24,
                                 27, 41, 42, 43, 44, 45, 46};
        vector<reg_type> RCRx {5, 6, 7, 8, 9, 10, 12, 14, 
                                16, 18, 20, 23, 26};
        vector<reg_type> CxRx {21};
        vector<reg_type> RxRx {22, 25, 28, 31, 34, 35, 36, 37};
        vector<reg_type> RxRC {29, 32};
        vector<reg_type> RxRR {30, 33};
        vector<reg_type> xxLx {38};
        vector<reg_type> xxRx {39};
        vector<reg_type> RxLL {40};

        //Forming the string to be returned
        if(register_inserted(this->inst, xxxx)){
                buffer << "L" << this->label << ":\n";
        }
        //Pick up the label of the inst
        buffer << instruct_to_string[this->inst];

        //Need to check each register content
        if(this->op1 >= 0) {
                //Need to check each form of usage
                if(register_inserted(this->inst,RRRx)){
                        buffer << " r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,RCRx)){
                        buffer << " r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,CxRx)){
                        buffer << " " << this->op1;
                }
                if(register_inserted(this->inst,RxRx)){
                        buffer << " r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,RxRC)){
                        buffer << " r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,RxRR)){
                        buffer << " r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,RxLL)){
                        buffer << " r" << get_register_name(this->op1);
                }
        }

        //Need to check each register content
        if(this->op2 >= 0) {
                //Need to check each form of usage
                if(register_inserted(this->inst,RRRx)){
                        buffer << ", r" << get_register_name(this->op1);
                }
                if(register_inserted(this->inst,RCRx)){
                        buffer << ", " << this->op2;
                }
        }

        if(!register_inserted(this->inst,xxxx)){
                buffer << " =>";
        }

        if(this->op3 >= 0) {
                //Need to check each form of usage
                if(register_inserted(this->inst,RRRx)){
                        buffer << " r" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,RCRx)){
                        buffer << " r" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,CxRx)){
                        buffer << " r" << this->op3;
                }
                if(register_inserted(this->inst,RxRx)){
                        buffer << " r" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,RxRC)){
                        buffer << " r" << this->op3;
                }
                if(register_inserted(this->inst,RxRR)){
                        buffer << " r" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,xxLx)){
                        buffer << " L" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,xxRx)){
                        buffer << " r" << get_register_name(this->op3);
                }
                if(register_inserted(this->inst,RxLL)){
                        buffer << "L" << this->op3;
                }
        }

        //Need to check each register content
        if(this->op4 >= 0) {
                //Need to check each form of usage
                if(register_inserted(this->inst,RxRC)){
                        buffer << ", " << this->op4;
                }
                if(register_inserted(this->inst,RxRR)){
                        buffer << ", r" << get_register_name(this->op4);
                }
                if(register_inserted(this->inst,RxLL)){
                        buffer << ", L" << this->op4;
                }
        }

        buffer << endl;
        cout << buffer.str();

        return buffer.str();

}

void ILOC_struct::code_attachment(vector<Command> from) {
    for (auto& e : from) {
        this->code_lines.push_back(e);
    }
}

//DONE - Func pra gravar uma instrução
//DONE - Func pra gerar o output
