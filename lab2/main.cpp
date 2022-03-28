#include<iostream>
#include<cmath>
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
  //Не работает -.123
  //Не работают слишком большие числа

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
bool isArmStrongNumber(string number) {
  int size = number.size();
  long armstrong_number = 0;
  for(char i : number) {
    armstrong_number += pow(atol(&i), size);
  }
  if(armstrong_number == stol(number)){
    return true;
  }
  return false;
}
void zad1() {
  bool failed;
  string element;
  do {
    failed = false;
    cout << "Enter a number: ";
    cin >> element;
    if(!isNumeric(element)) {
      failed = true;
      cout  << "Wrong input! Not a number!" << endl;
    }
    if(!failed && stol(element) < 0) {
      failed = true;
      cout << "Number must be more than a zero!" << endl;
    }
    if(!failed && hasPoint(element)) {
      failed = true;
      cout << "Number must be an integer!" << endl;
    }
  } while(failed);
  string message = isArmStrongNumber(element) ? "It's armstrong number!" : "It's not an armstrong number";
  cout << message << endl;
}

bool isPolindrome(int number) {
  if(number < 1) {
    return false;
  }
  if(number < 10) {
    return true;
  }

  int numberToCheck = number;
  int newNumber = 0;
  while (number > 0) {
    int lastDigit = number % 10;
    // cout << dig <<endl;
    newNumber = newNumber * 10 + lastDigit;
    // cout << rev <<endl;
    number = number / 10;
    // cout << number <<endl << endl;
  }
  return numberToCheck == newNumber;

}
void zad3() {
  int number;
  cout << "Enter natural number: ";
  cin >> number;
  if(number < 0) {
    cout << "This is not a natural number!" << endl;
    return;
  }
  string message = "";
  if(isPolindrome(number)) {
    message = "This is polindrome!";
  } else {
    message = "This is not polindrome!";
  }
  cout << message << endl;
  return;
}

int main() {
    // zad1(); //Готово
    // zad3(); //Готово
    // zad6();
    // zad7();
    // zad8();
    // zad12();
}
