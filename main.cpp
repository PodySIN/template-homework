#include <iostream>

// 
template< class T >
T* merge(const T* const * a, size_t sa, const size_t * sai, T* c)
{
  size_t pos = 0;
  for (; pos < sa; pos++) {
    if (sai[pos] != 0) {
      break;
    }
  }
  if (pos == sa) {
    return c;
  }
  size_t* sai2 = new size_t[sa];
  for (size_t i = 0; i < sa; i++) {
    sai2[i] = 0;
  }
  size_t index = 0;
  while(true) {
    for (size_t i = 0; i < sa; i++) {
      if (sai2[i] != sai[i]) {
        if (a[pos][sai2[pos]] > a[i][sai2[i]]) { // оператор сравнения >
          pos = i;
        }
      }
    }
    try {
      c[index++] = a[pos][sai2[pos]]; // оператор копирующего присваивания
    } catch (...) {
      delete[] sai2;
      throw;
    }
    sai2[pos]++;
    if (sai2[pos] == sai[pos]) {
      for (size_t i = 0; i < sa; i++) {
        if (sai2[i] != sai[i]) {
          pos = i;
        }
      }
      if (sai2[pos] == sai[pos]) {
        break;
      }
    }
  }
  delete[] sai2;
  return c;
}

template< class T >
void print(T* arr, size_t size)
{
  std::cout << arr[0];
  for (size_t i = 1; i < size; i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

int main()
{
  size_t size = 6;
  size_t * sizes = new size_t[size]{6, 2, 5, 3, 5, 7};
  int* arr1 = new int[6]{1, 2, 3, 4, 5, 6};
  int* arr2 = new int[2]{-15, 125};
  int* arr3 = new int[5]{-30, -15, -8, 4, 17};
  int* arr4 = new int[3]{-20, 3, 60};
  int* arr5 = new int[5]{-333, -222, -15, 17, 333};
  int* arr6 = new int[7]{-444, -222, 0, 222, 444, 666, 888};
  int** arr = new int*[size]{arr1, arr2, arr3, arr4, arr5, arr6};
  size_t res_size = 28;
  int* res = new int[res_size];
  merge(arr, size, sizes, res);
  print(res, res_size);
}


