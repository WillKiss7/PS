int s = 1, e = 1e9 + 1; // [s, e) range
while(s + 1 < e){
    int m = (s + e) >> 1;
    if(ok(m)) s = m;
    else e = m;
}
cout << s;

int s = 1, e = 1e9; // [s, e] range
while(s < e){
    int m = (s + e + 1) >> 1;
    if(ok(m)) s = m;
    else e = m - 1;
}
cout << s;
