#include <iostream>
extern "C" { 
    #include "fa.h" 
}
#include <map>
#include <vector>

int main(int argNum, const char **args) {

    if (argNum!=2) {
        std::cerr << "Error: Expected exactly one argument, which is the RegEx.\n";
        return 1;
    }

    std::string expression = args[1];
    struct fa *automaton;
    int ret = fa_compile(expression.c_str(), expression.size(), &automaton);

    if (ret==REG_NOERROR) {
        // Minimize
        if (fa_minimize(automaton)!=0) {
            std::cerr << "Error minimzing the automaton\n";
        } else {
            
            std::map<struct state *,int> stateNums;
            stateNums[fa_state_initial(automaton)] = 0;
            std::vector<struct state*> statePointers;
            statePointers.push_back(fa_state_initial(automaton));
            
            for (unsigned int stateNum=0;stateNum<stateNums.size();stateNum++) {
                size_t nofTrans = fa_state_num_trans(statePointers[stateNum]);
                if (fa_state_is_accepting(statePointers[stateNum])) std::cout << ":acc " << stateNum << "\n";
                for (unsigned int i=0;i<nofTrans;i++) {
                    struct state *to;
                    unsigned char min;
                    unsigned char max;
                    if (fa_state_trans(statePointers[stateNum],i,&to, &min, &max)==-1) {
                        std::cerr << "Error reading transition.\n";
                        return 1;
                    } else {
                        if (stateNums.count(to)==0) {
                            stateNums[to] = statePointers.size();
                            statePointers.push_back(to);                        
                        }
                        std::cout << stateNum << " " << stateNums[to] << " " << min << " " << max << "\n";
                    }
                }            
            }
            
            
        
            fa_free(automaton);
        }
    } else {
        std::cerr << "Error compiling the regular expression.\n";
    }

}
