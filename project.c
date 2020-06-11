#include<stdlib.h>
 
#include<stdio.h>
 
#include<string.h>
 
 
static int convert_to_int(char ch) {
 
  return (int)(ch - 48);
 
}
 
 
static char convert_to_char(int in) {
 
  return (char)(in + 48);
 
}
 char* intal_add(char* intal1, char* intal2) {
 
  int len1 = strlen(intal1);
 
  int len2 = strlen(intal2);
 
 
  int a = (len1 > len2)? len1 + 1: len2 + 1;
 
  int b = (len1 > len2)? len2: len1;
 
  
 
  int i, digit1, digit2, ansdigit, c = 0;
 
  char* result = (char*)malloc((a + 1) * sizeof(char));
 
 
  for(i = 0 ; i < b; ++i) {
 
    digit1 = convert_to_int(intal1[len1 - 1 - i]);
 
    digit2 = convert_to_int(intal2[len2 - 1 - i]);
 
 
    ansdigit = digit1 + digit2 + c;
 
    c = (ansdigit > 9)? 1: 0;
 
    ansdigit = (ansdigit > 9)? ansdigit - 10: ansdigit;
 
 
    result[a - 1 - i] = convert_to_char(ansdigit);

  }
 
 
  while(i < a - 1) {
 
    if(len1 > len2) {
 
      ansdigit = convert_to_int(intal1[len1 - 1 - i]) + c;
 
      c = (ansdigit > 9)? 1: 0;
 
      ansdigit = (ansdigit > 9)? ansdigit - 10: ansdigit;
 
 
      result[a - 1 - i] = convert_to_char(ansdigit);
 
    } else {
 
      ansdigit = convert_to_int(intal2[len2 - 1 - i]) + c;
 
      c = (ansdigit > 9)? 1: 0;
 
      ansdigit = (ansdigit > 9)? ansdigit - 10: ansdigit;
 
 
      result[a - 1 - i] = convert_to_char(ansdigit);
 
    }
 
 
    ++i;
 
  }
 
 
  if(c != 0) {
 
    result[0] = convert_to_char(c);
 
    result[a] = '\0';
 
  } else {
 
    for(i = 0; i < a - 1; ++i) {
 
      result[i] = result[i + 1];
 
    }
 
 
    result = (char*)realloc(result, a * sizeof(char));
 
    result[a - 1] = '\0';
 
  }
 
 
  return result;
 
}
 
 int intal_compare(char* intal1, char* intal2) {
 
  int len1 = strlen(intal1);
 
  int len2 = strlen(intal2);
 
 
  if(len1 > len2)
 
    return 1;
 
  else if(len2 > len1)
 
    return -1;
 
 
  for(int i = 0; i < len1; ++i) {
 
    if(intal1[i] > intal2[i])
 
      return 1;
 
    else if(intal2[i] > intal1[i])
 
      return -1;
 
  }
 
  
 
  return 0;
 
}
 
 
 char* intal_diff(char* intal1, char* intal2) {
 
  int cmp = intal_compare(intal1, intal2);
 
  if(cmp == 0) {
 
    char* result = (char*)malloc(2 * sizeof(char));
 
    result[0] = '0';
 
    result[1] = '\0';
 
    return result;
 
  } else if(cmp == -1) {
 
    char* temp = intal1;
 
    intal1 = intal2;
 
    intal2 = temp;
 
  }
 
 
  int len1 = strlen(intal1);
 
  int len2 = strlen(intal2);
 
 
  int l = (len1 > len2)? len1: len2;
 
  int s = len1 + len2 - l;
 
  
 
  int i, digit1, digit2, ansdigit, c = 0;
 
  char* result = (char*)malloc((l + 1) * sizeof(char));
 
 
  for(i = 0 ; i < s; ++i) {
 
    digit1 = convert_to_int(intal1[len1 - 1 - i]) - c;
 
    digit2 = convert_to_int(intal2[len2 - 1 - i]);
 
 
    c = (digit2 > digit1)? 1: 0;
 
    digit1 = (digit2 > digit1)? digit1 + 10: digit1;
 
    ansdigit = digit1 - digit2;
 
 
    result[l - 1 - i] = convert_to_char(ansdigit);
 
  }
 
 
  while(i < l) {
 
    ansdigit = convert_to_int(intal1[len1 - 1 - i]) - c;
 
    c = (ansdigit > -1)? 0: 1;
 
    ansdigit = (ansdigit > -1)? ansdigit: ansdigit + 10;
 
 
    result[l - 1 - i] = convert_to_char(ansdigit);
 
 
    ++i;
 
  }
 
 
  for(i = 0; i < l; ++i) {
 
    if(result[i] != '0')
 
      break;
 
  }
 
 
  result[l] = '\0';
 
  int extra = i;
 
  if(extra != 0) {
 
    for(i = 0; i <= l - extra; ++i)
 
      result[i] = result[i + extra];
 
 
    result = realloc(result, (l - extra + 1) * sizeof(char));
 
  }
 
 
  return result;
 
}
 
 
char* intal_multiply(char* intal1, char* intal2) {
 
  if(strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0) {
 
    char* result = (char*)malloc(2 * sizeof(char));
 
    result[0] = '0';
 
    result[1] = '\0';
 
    return result;
 
  }
 
 
  int i, j, digit1, digit2, digit3, ansdigit, carry= 0;
 
  int len1 = strlen(intal1);
 
  int len2 = strlen(intal2);
 
 
  int l = len1 + len2;
 
  char* result = (char*)malloc((l + 1) * sizeof(char));
 
 
  for(i = 0; i < l; ++i)
 
    result[i] = '0';
 
 
  for(i = 0; i < len1; ++i) {
 
    carry= 0;
 
    for(j = 0; j < len2; ++j) {
 
       digit1 = convert_to_int(intal1[len1 - 1 - i]);
 
       digit2 = convert_to_int(intal2[len2 - 1 - j]);
 
       digit3 = convert_to_int(result[l - 1 - i - j]);
 
 
      ansdigit = (digit1 * digit2) + carry+ digit3;
 
      carry= ansdigit / 10;
 
      ansdigit = ansdigit % 10;
 
 
      result[l - 1 - i - j] = convert_to_char(ansdigit);
 
    }
 
 
    for(j = len2 + i; j < len2 + len1; ++j) {
 
       digit3 = convert_to_int(result[l - 1 - j]);
 
 
      ansdigit = carry+ digit3;
 
      carry= ansdigit / 10;
 
      ansdigit = ansdigit % 10;
 
      result[l - 1 - j] = convert_to_char(ansdigit);
 
    }
 
  }
 
 
  result[l] = '\0';
 
  if(result[0] == '0') {
 
    for(i = 0; i <= l; ++i)
 
      result[i] = result[i + 1];
 
 
    result = realloc(result, l * sizeof(char));
 
  }
 
 
  return result;
 
}
 
 
char* intal_mod(char* intal1, char* intal2) {
 
  int cmp = intal_compare(intal1, intal2);
 
  if(cmp == -1) {
 
    char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
 
    strcpy(result, intal1);
 
    return result;
 
  } else if(cmp == 0) {
 
    char* result = (char*)malloc((2) * sizeof(char));
 
    strcpy(result, "0");
 
    return result;
 
  }
 
 
  int p = strlen(intal2);
 
  int end = strlen(intal1);
 
  char* current = (char*)malloc((strlen(intal2) + 2) * sizeof(char));
 
  for(int i = 0; i < p; ++i)
 
    current[i] = intal1[i];
 
  current[p] = '\0';
 
 
  do {
 
    if(intal_compare(current, intal2) == -1 && p < end) {
 
      int len = strlen(current);
 
      if(strcmp(current, "0") == 0)
 
        len = 0;
 
      current[len] = intal1[p];
 
      current[len + 1] = '\0';
 
      ++p;
 
    }
 
 
    if(intal_compare(current, intal2) != -1){
 
      char* result = intal_diff(current, intal2);
 
      while(intal_compare(result, intal2) > -1) {
 
        char* temp = result;
 
        result = intal_diff(result, intal2);
 
        free(temp);
 
      }
 
      
 
      strcpy(current, result);
 
      free(result);
 
    }    
 
  } while(p < end);
 
 
  current = realloc(current, (strlen(current) + 1) * sizeof(char));
 
  current[strlen(current) + 1] = '\0';
 
  return current;
 
}
 
 
char* intal_pow(const char* intal1, unsigned int n)
{
	
	int half1=0;
	int half2=0;
	if(n%2==0){
		half1 = n/2;
		half2=0;
	}
	else{
		half1 = n/2;
		half2 = 1;
	}
	
	char* s1 =(char*)malloc(sizeof(char)*1001);
	strcpy(s1,intal1);
	
	char* temp=(char*)malloc(sizeof(char)*1001);;
	strcpy(temp,"1");


	for(int i=0;i<half1;i++){
		temp = intal_multiply(s1,temp);
		temp = intal_multiply(s1,temp);
	}
	
	if(half2){
		temp = intal_multiply(s1,temp);
	}
	
	
	free(s1);
	return temp;
		
}
 
char* intal_gcd(char* intal1, char* intal2) {
 
  char* a = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
 
  strcpy(a, intal1);
 
  char* b = (char*)malloc((strlen(intal2) + 1) * sizeof(char));
 
  strcpy(b, intal2);
 
 
  int flag = strcmp(a, "0");
 
  while(flag != 0) {
 
    char* temp = b;
 
    b = a;
 
    a = intal_mod(temp, a);
 
 
    free(temp);
 
    flag = strcmp(a, "0");
 
  }
 
 
  free(a);
 
  return b;
 
}
 
 
char* intal_fibonacci(unsigned int n) {
 
  char* a = (char*)malloc(2 * sizeof(char));
 
  a[0] = '0';
 
  a[1] = '\0';
 
 
  if(n == 0)
 
    return a;
 
 
  char* b = (char*)malloc(2 * sizeof(char));
 
  b[0] = '1';
 
  b[1] = '\0';
 
 
  if(n == 1)
 
    return b;
 
 
  for(int i = 1; i < n; ++i) {
 
    char* c = intal_add(a, b);
 
    free(a);
 
    a = b;
 
    b = c;
 
  }
 
 
  free(a);
 
  return b;
 
}
 
 
char* intal_factorial(unsigned int n) {
 
  char* start = (char*)malloc(2 * sizeof(char));
 
  start[0] = '1';
 
  start[1] = '\0';
 
 
  if(n < 2)
 
    return start;
 
 
  char* result = (char*)malloc(2 * sizeof(char));
 
  result[0] = '1';
 
  result[1] = '\0';
 
 
  char* step = (char*)malloc(2 * sizeof(char));
 
  step[0] = '1';
 
  step[1] = '\0';
 
 
  for(int i = 1; i <n; ++i) {
 
    char* tmp = start;
 
    start = intal_add(start, step);
 
    free(tmp);
 
 
    tmp = result;
 
    result = intal_multiply(start, result);
 
    free(tmp);
 
  }
 
 
  free(start);
 
  free(step);
 
  
 
  return result;
 
}
 
 
char* intal_bincoeff(unsigned int n, unsigned int k) {
 
  char** c = (char**)malloc((k+1) * sizeof(char*));
 
  for(int i = 0; i < k + 1; ++i) {
 
    c[i] = (char*)malloc(2 * sizeof(char));
 
    c[i][0] = '0';
 
    c[i][1] = '\0';
 
  }
 
 
  c[0][0] = '1';
 
 
  for(int i = 1; i < n + 1; ++i) {
 
    int j = (i > k)? k: i;
 
    while(j > 0) {
 
      char* tmp = c[j];
 
      c[j] = intal_add(c[j], c[j - 1]);
 
      free(tmp);
 
      --j;
 
    }
 
  }
 
 
  char* result = (char*)malloc((strlen(c[k]) + 1) * sizeof(char));
 
  strcpy(result, c[k]);
 
  
 
  for(int i = 0; i < k + 1; ++i) {
 
    free(c[i]);
 
  }
 
  free(c);
 
 
  return result;
 
}
 
 
int intal_max(char **arr, int n) {
 
  int pos = 0;
 
  for(int i = 1; i < n; ++i) {
 
    if(intal_compare(arr[pos], arr[i]) < 1)
 
      pos = i;
 
  }
 
 
  return pos;
 
}
 
 
int intal_min(char **arr, int n) {
 
  int pos = 0;
 
  for(int i = 1; i < n; ++i) {
 
    if(intal_compare(arr[pos], arr[i]) > -1)
 
      pos = i;
 
  }
 
 
  return pos;
 
}
 
 
int intal_search(char **arr, int n, const char* key) {
 
  int pos = -1;
 
  for(int i = 0; i < n; ++i) {
 
    if(intal_compare(arr[i], (char*)key) == 0) {
 
      pos = i;
 
      break;
 
    }
 
  }
 
 
  return pos;
 
}
 
 
int intal_binsearch(char **arr, int n, const char* key) {
 
  int start = 0;
 
  int end = n - 1;
 
 
  while(start <= end) {
 
    int mid = (start + end) / 2;
 
    int cmp = intal_compare(arr[mid], (char*)key);
 
    if(cmp == 0) {
 
      return mid;
 
    } else if(cmp > 0) {
 
      end = mid - 1;
 
    } else {
 
      start = mid + 1;
 
    }
 
  }
 
 
  return -1;
 
}
 
 
static int partition(char** arr, int l, int h) {
 
  int i = l - 1;
 
  char* pivot = arr[h];
 
 
  for(int j = l; j < h; ++j) {
 
    if(intal_compare(arr[j], pivot) < 0) {
 
      ++i;
 
      char* tmp = arr[i];
 
      arr[i] = arr[j];
 
      arr[j] = tmp;
 
    }
 
  }
 
 
  char* tmp = arr[i + 1];
 
  arr[i + 1] = arr[h];
 
  arr[h] = tmp;
 
 
  return (i + 1);
 
}
 
 
static void quicksort(char** arr, int l, int h) {
 
  if(l < h) {
 
    int pi = partition(arr, l, h);
 
    quicksort(arr, l, pi - 1);
 
    quicksort(arr, pi + 1, h);
 
  }
 
}
 
 
void intal_sort(char **arr, int n) {
 
  quicksort(arr, 0, n - 1);
 
}
 
 
char* coin_row_problem(char **arr, int n) {
 
  char** f = (char**)malloc((n + 1) * sizeof(char*));
 
  f[0] = (char*)malloc(2 * sizeof(char));
 
  f[0][0] = '0';
 
  f[0][1] = '\0';
 
 
  for(int i = 0; i < n; ++i) {
 
    f[i + 1] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));
 
    strcpy(f[i + 1], arr[i]);
 
  }
 
 
  for(int i = 2; i < n + 1; ++i) {
 
    char* val = intal_add(arr[i -1], f[i - 2]);
 
    if(intal_compare(val, f[i - 1]) > 0) {
 
      char* tmp = f[i];
 
      f[i] = val;
 
      free(tmp);
 
    } else {
 
      free(f[i]);
 
      f[i] = (char*) malloc((strlen(f[i - 1]) + 1) * sizeof(char));
 
      strcpy(f[i], f[i - 1]);
 
      free(val);
 
    }
 
  }
 
 
  char* result = (char*)malloc((strlen(f[n]) + 1) * sizeof(char));
 
  strcpy(result, f[n]);
 
 
  for(int i = 0; i < n + 1; ++i) {
 
    free(f[i]);
 
  }
 
  free(f);
 
 
  return result;
 
}
 

