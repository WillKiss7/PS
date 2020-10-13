#define MAX 1000000
    for(int i = 2; i * i <= MAX; i++){
        if(check[i]) continue;
        for(int j = i * i; j <= MAX; j += i)
            check[j] = true;
    }
 
//When I use a vector which have prime number
vector<int> prime_number;
    for(int i = 2; i <= MAX; i++){ //You should search i [2, MAX]
        if(check[i]) continue;
        prime_number.push_back(i);
        for(int j = i * i; j <= MAX; j += i)
            check[j] = true;
    }
