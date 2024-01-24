```C++
// Pass-by-Reference Example

double average(double a, double b) {
    a = (a + b) / 2;
    return a;
}

void swap(double &a, double &b){
    double tmp = a;
    a = b;
    b = tmp;
}

const string & randomItem(const vector<string> &arr)
    return arr[rand() % arr.size()];

int main(){
    double a = 1, b = 2;
    double c = average(a, b);
    swap(a, b);
   
    srand(time(NULL)); // we need to initialize the random number generator
    vector<string> words = {"Hello", "World", "how", "are", "you"};
    
    const string & s = randomItem(words);
    return 0;
}