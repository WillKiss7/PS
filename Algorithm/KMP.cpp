//https://m.blog.naver.com/kks227/220917078260
//실패함수
int fail[MAX] = {0};
  for(int i=1, j=0; i<M; i++){
    while(j > 0 && W[i] != W[j]) j = fail[j-1];
    if(W[i] == W[j]) fail[i] = ++j;
  }
