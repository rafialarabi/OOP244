#include "Marks.h"
#include "Utils.h"
using namespace sdds;
namespace sdds {
    bool takeNum(string strNum, int& num, string& errorexecution) {
        num = 0;
        int len = strNum.length();;
        for (int i = 0; i < len; i++) {
            if (strNum[i] >= '0' && strNum[i] <= '9') {
                num *= 10;
                num += (strNum[i] - '0');
            }
            else {
                if (num == 0) {
                    errorexecution = "Invalid Number, try again: ";
                }
                else {
                    errorexecution = "Invalid trailing characters. try again: ";
                }
                num = 0;
                return false;
            }
        }
        return true;
    }

    int getInt(string prompt, int min, int max, string errorPrompt) {
        string strNum;
        int digit;
        string errorMsg = "";
        do {
            cout << prompt;
            getline(cin, strNum);
            if (takeNum(strNum, digit, errorMsg) && (min != -1 ? digit >= min : true)
                && (max != -1 ? digit <= max : true)) {
                break;
            }
            else {
                if (errorMsg.length() > 0) {
                    cout << errorMsg;
                }
                else {
                    cout << errorPrompt;
                }
            }

        } while (true);
        return digit;
    }
}