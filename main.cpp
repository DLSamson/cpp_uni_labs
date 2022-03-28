#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

//По списку 2. Задания: 2,8,4

void wait(string message = "") {
  if(message != "") {
    cout << message << endl;
  }
  string end;
  cin >> end;
}

//Лабораторная работа 1
bool is_fibbonachi(int number) {
  if(number < 0){
    return false;
  }
  int first = 0;
  int second = 1;
  int a = second;
  while(second <= number){
    a = second;
    second = first + second;
    first = a;
    if(first == number) {
      return true;
    }
  }
  return false;
}
float readFloat(string message) {
  cout << message;
  float val;
  cin >> val;
  return val;
}
bool isSquareTriangle(float *a, float *b, float *c) {
  float ab[] = {b[0] - a[0], b[1] - a[1]};
  float ac[] = {c[0] - a[0], c[1] - a[1]};
  float cb[] = {b[0] - c[0], b[1] - c[1]};

  double ab_len = sqrt(ab[0]*ab[0] + ab[1]*ab[1]);
  double ac_len = sqrt(ac[0]*ac[0] + ac[1]*ac[1]);
  double cb_len = sqrt(cb[0]*cb[0] + cb[1]*cb[1]);

  cout << ab_len << endl;
  cout << ac_len << endl;
  cout << cb_len << endl;

  double ab_ac_cos = (ab[0]*ac[0]+ab[1]*ac[1])/(ab_len*ac_len);
  double ac_cb_cos = (ac[0]*cb[0]+ac[1]*cb[1])/(ac_len*cb_len);
  double ab_cb_cos = (ab[0]*cb[0]+ab[1]*cb[1])/(ab_len*cb_len);

  cout << acos(ab_ac_cos) * 180/M_PI << endl;
  cout << acos(ac_cb_cos) * 180/M_PI << endl;
  cout << acos(ab_cb_cos) * 180/M_PI << endl;

  bool result = false;
  if (acos(ab_ac_cos) * 180/M_PI == 90 ||
      acos(ac_cb_cos) * 180/M_PI== 90 ||
      acos(ab_cb_cos) * 180/M_PI== 90
    ) {
    result = true;
  }

  return result;
}
bool isNumbersTheSame(string str_number) {
    int str_len = str_number.length();
    if(str_len == 1) {
      return true;
    }
    int result = false;
    for(int i = 0; i < str_len; i++) {
      for(int j = 0; j < str_len; j++) {
        if(i != j) {
          if(str_number[i] == str_number[j]) {
            result += 1;
          }
          else {
            result -= 1;
          }
        }
      }
    }
    if(result < str_len * (str_len -1)) {
        return false;
    } else {
        return true;
    }
}

//Лаборатоная работа 2.
bool isTwoDigitNumber(int number) {
  if((10 <= number && number <= 99) || (number <= -10 && number >= -99)) {
    return true;
  }
  return false;
}
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
string cutDownString(string str, int size) {
  if(str.size() < size) {
    return str;
  }
  string new_str = "";
  for(int i = 0; i < size; i++) {
    new_str += str[i];
  }
  return new_str;
}

void printArray(int *array, int size, string message = "Element\t") {
  for (int i = 0; i < size; i++) {
    cout << message << i << ": " << array[i] << endl;
  }
}
void printArray(double *array, int size, string message = "Element\t") {
  for (int i = 0; i < size; i++) {
    cout << message << i << ": " << array[i] << endl;
  }
}

//For task2
void fill_array_twodigits(int*array, int size) {
  for (int i = 0; i < size; i++) {
    bool failed;
    string element;
    do {
      failed = false;
      printf("Enter a two digit number for %i: ", i+1);
      cin >>  element;

      if(element.size() > 10) {
        cout << "[Warning]: Your number is too big, it will be cut of" << endl;
        element = cutDownString(element, 10);
      }

      if(!isNumeric(element)) {
        failed = true;
        cout << "[ Error ]: You typed " << element << ", it's not a number" << endl;
      }
      if(!failed && !isTwoDigitNumber(stoi(element))) {
        failed = true;
        cout << "[ Error ]: You typed " << element << ", it's not a two digit number" << endl;
      }

      if(!failed && hasPoint(element)) {
        cout << "[Warning]: This is not an integer, everything after point will be removed!" << endl;
      }

    } while(failed);
    array[i] = stoi(element);
  }
}
void array_slice_elements(int *first_array, int *second_array, int size) {
  //Takes elements of first array and puts it in the second one;
  for (int i = 0; i < size; i++) {
    int element = first_array[i];
    int first, second;
    first = element / 10;
    //Make absolute if needs
    second = element % 10;

    int first_index = i*2;
    int second_index = i*2+1;
    second_array[first_index] = first;
    second_array[second_index] = second;
  }
}
//For task8
void array_sum_digits(int *first_array, int *second_array, int size) {
  //Takes elements of first array and puts its sum of digits in the second one;
  for (int i = 0; i < size; i++) {
    int element = first_array[i];
    int first, second;
    first = element / 10;
    second = element % 10;
    second_array[i] = first + second;
  }
}
//For task2_4
void fill_array(double *array, int size) {
  for (int i = 0; i < size; i++) {
    bool failed;
    string element;
    do {
      failed = false;
      printf("Enter a number %i: ", i+1);
      cin >> element;

      if(element.size() > 10) {
        cout << "[Warning]: Your number is too big, it will be cut of" << endl;
        element = cutDownString(element, 10);
      }

      if(!isNumeric(element)) {
        failed = true;
        cout << "You typed " << element << ", it's not a number" << endl;
      }
    } while(failed);
    array[i] = stod(element);
  }
}
void buble_sort(double *array, int size) {
  bool isChanged;
  do {
    isChanged = false;
    for(int i = 0; i < size; i++) {
      double frd;
      if(i != size -1 &&
        array[i] > array[i+1]
      ) {
        frd = array[i];
        array[i] = array[i+1];
        array[i+1] = frd;
        isChanged = true;
      }
    }
  } while(isChanged);
}
void unite_arrays(double *first, double *second, double *third, int first_size, int second_size) {
  for (int i = 0; i < first_size; i++) {
    third[i] = first[i];
  }
  int full_size = second_size+first_size;
  for (int i = first_size; i < full_size; i++) {
    third[i] = second[i-first_size];
  }
}

//Для 4 лабы
string string_merge(string str_one, string str_two) {
  string result;
  string element;
  int size = str_one.size();
  for(int i = 0; i < size; i++) {
    result += str_one[i];
    result += str_two[i];
  }
  return result;
}

void task1_2() {
  //Task 2;
  bool failed;
  string element;
  do {
    failed = false;
    cout << "Enter number: ";
    cin >> element;

    if(element.size() > 10) {
      cout << "[Warning]: Your number is too big, it will be cut of" << endl;
      element = cutDownString(element, 10);
    }

    if(!isNumeric(element)) {
      failed = true;
      cout << "[ Error ]: You entered not a number" << endl;
    }

    if(!failed && ((stoi(element) > 0 && stoi(element) < 1) || hasPoint(element) ) ) {
      failed = true;
      cout << "[ Error ]: Number must be an integer" << endl;
    }
    if(!failed && stoi(element) < 0) {
      failed=true;
      cout << "[ Error ]: Number must be more than a zero" << endl;
    }

  } while(failed);

  int number = stoi(element);
  string message = is_fibbonachi(number) ? "it's fibonachi" : "it's not fibonachi";
  cout << message << endl;
}
void task1_4() {
  //Task 4;
  float *pointA = new float[2] {0,0};
  float *pointB = new float[2] {readFloat("Enter x1: "), readFloat("Enter y1: ")};
  float *pointC = new float[2] {readFloat("Enter x2: "), readFloat("Enter y2: ")};
  string message = isSquareTriangle(pointA, pointB, pointC) ? "Yes, it's square triangle" : "No, it's not square triangle";
  cout << message << endl;
}
void task1_8() {
  //Task 8;
  string s_number;
  bool failed;
  do {
    failed = false;
    cout << "Enter integer more than zero: ";
    cin >> s_number;
    if(!isNumeric(s_number)) {
      failed = true;
      cout << "[ Error ]: " << s_number<< " not a number" << endl;
    }
    if(!failed && stoi(s_number) < 0) {
      failed = true;
      cout << "[ Error ]: " << s_number << " less than zero!" << endl;
    }

    if(s_number.size() > 11) {
      cout << "[Warning]: Your number is too big, it will be cut of" << endl;
      s_number = cutDownString(s_number, 12);
    }

  } while(failed);
  string message = isNumbersTheSame(s_number) ? "Numbers are the same" : "Numbers are NOT the same";
  cout << message << endl;
}


void task2_2() {
  int size = 8;
  int *first_array = new int[size];
  fill_array_twodigits(first_array, size);
  // printArray(first_array, size, "Element ");
  int *second_array = new int[size*2];
  array_slice_elements(first_array, second_array, size);
  printArray(second_array, size*2, "Element ");

  delete []second_array;
  delete []first_array;
}
void task2_4() {
  double *first_array = new double[9];
  double *second_array = new double[7];
  double *third_array = new double[9+7];
  printf("Enter first array\n");
  fill_array(first_array, 9);
  printf("Enter second array\n");
  fill_array(second_array, 7);

  unite_arrays(first_array, second_array, third_array, 9,7);

  printf("BeforeSort:\n");
  printArray(third_array, 9+7);

  buble_sort(third_array, 9+7);
  //Большие дробные числа отваливаются

  printf("AfterSort:\n" );
  printArray(third_array, 9+7);
}
void task2_8() {
  int size = 9;
  int *first_array = new int[size];
  fill_array_twodigits(first_array, size);
  // printArray(first_array, size, "Element ");
  int *second_array = new int[size];
  array_sum_digits(first_array, second_array, size);
  printArray(second_array, size, "Element ");

  delete []second_array;
  delete []first_array;
}


void task4_2() {
  //Посчитать кол-во слов

}
void task4_4() {
  //Удалить все латиснкие буквы

}
void task4_8() {
  //Слить две строки в одну с чередованием элементов
  string first_str, second_str, third_str;
  bool failed;
  do {
    failed = false;
    cout << "Enter a string: ";
    getline(cin, first_str);
    cout << "Enter a string size of " << first_str.size() << ": ";
    getline(cin, second_str);
    if(first_str.size() != second_str.size()) {
      failed = true;
      cout << "[ Error ]: Strings are not the same size!" << endl;
    }
    if(!failed && (first_str.size() < 1 || second_str.size() < 1) ) {
      failed = true;
      cout << "[ Error ]: One of these strings was empty!" << endl;
    }
  } while(failed);

  third_str = string_merge(first_str, second_str);
  cout << third_str << endl;
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
void armstrong_number() {
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

int main() {
  setlocale(0, "");
  armstrong_number();
  //Лабораторная работа 2.
  // task1_2();
  // task1_4();
  // task1_8();

  //Лаборатоная работа 3.
  // task2_2();
  // task2_4();
  // task2_8();

  //Лаборатоная работа 4.
  // task4_2();
  // task4_4();
  // task4_8();



  // wait();
  return 0;
}
