void rotateString(char *st, int posi, int posj) {
    char temp;
    while (posi < posj) {
        temp = st[posi];
        st[posi] = st[posj];
        st[posj] = temp;
        posi++; posj--;
    }
}

void rotate(char *st, int k) {
    if (st == NULL)
        return;
    int len = strlen(st);
    rotateString(st, 0, len-1);
    rotateString(st, 0, k-1);
    rotateString(st, k, len-1);
}
