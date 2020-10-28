const int ROZ = 10;

void sclanie(int p, int q, int k, int tab[]){
    int wynik[ROZ];
    for(int i = 0, pi = p, qi = q; i < k; i++){
        wynik[i] = tab[pi] > tab[qi] ? tab[qi++] : tab[pi++];
        pi = pi >= q ? qi : pi;
        qi = qi >= k || qi < pi ? pi : qi;
    }
    for(int i =0 ;i < k; i++)
        tab[i] = wynik[i];
}

void mergesort(int l, int p, int tab[]){
    if(l < p){
        int s = l+p/2;
        mergesort(l, s, tab);
        mergesort(s+1, p, tab);
        sclanie(l, s+1, p, tab);
    }
}