//Zadanie 2

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
bool isPerfectNumber(int number) {
    if(number % 2 != 0) {
        return false;
    }
    if(number == 6) {
        return true;
    }
    for(int i = 1; i < number; i++) {
        int perfectNumber = i*i*((2*i*i)-1);
        if(perfectNumber == number) {
            return true;
        }
    }
    return false;
}
int getSizeWithoutPerfectNumbers(int *array, int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        bool toDelete = isPerfectNumber(array[i]);
        if(!toDelete) {
            counter++;
        }
    }
    return counter;
}
int* deletePerfectNumbers(int* array, int size) {
    int counter = 0;
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " : ";
        bool toDelete = isPerfectNumber(array[i]);
        if(toDelete) {
            cout << "delete" << endl;
        }
        else {
            cout << "nope" << endl;
            counter++;
        }
    }
    cout << endl;

    int *newArray = new int[counter];
    int position = 0;
    for (int i = 0; i < size; i++) {
        if(isPerfectNumber(array[i])) {
            newArray[position] = array[i];
            position++;
        }
    }

    delete [] array;

    return newArray;
}


int main() {
    int size = getInt("Enter size of array: ");
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = getInt("Enter number for " + to_string(i+1) + ": ");
    }
    cout << "Link to array is " << array << endl;
    cout << "Size is " << size << endl;

    int newSize = getSizeWithoutPerfectNumbers(array, size);
    array = deletePerfectNumbers(array, size);
    size = newSize;

    cout << "Link to array is " << array << endl;
    cout << "Size is " << size << endl << endl;

    delete [] array;
    return 0;
}
