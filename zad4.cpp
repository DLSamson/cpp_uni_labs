//Zadanie4
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

bool isNumeric(string str) {
  bool pointflag = false;
  int str_size = str.size();
  if(str_size < 2) {
    return isdigit(str[0]);
  }

  if (str_size > 1 && str[0] == '-' &&  str[1] == '.') {
    return false;
  }
  if (str[0] == '.') {
    return false;
  }
  for(int i = 0; i < str_size; i++) {
    if(!isdigit(str[i])) {
      if(str[i] == '-' && i != 0) {
        return false;
      } else if(str[i] == '.' && pointflag == true) {
        return false;
      } else if(str[i] != '.' && str[i] != '-') {
        return false;
      }
    }

    if(str[i] == '.') {
      pointflag = true;
    }

  }
  return true;
}
bool hasPoint(string str) {
  for(char i : str) {
    if(i =='.') {
      return true;
    }
  }
  return false;
}
int getInt(string message) {
    bool failed = false;
    string number;
    do {
        failed = false;
        cout << message;
        cin >> number;

        if(!isNumeric(number)) {
            failed = true;
        }
        if(hasPoint(number)) {
            failed = true;
        }
        if(stoi(number) < 0) {
            failed = true;
        }
    } while(failed);
    return stoi(number);
}

bool isSimpleNumber(int number) {

}
void buble_sort(int* array, int size) {

}

int main() {
    int size = getInt("Enter size of array: ");
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = getInt("Enter number for " + to_string(i+1) + ": ");
    }


    return 0;
}
