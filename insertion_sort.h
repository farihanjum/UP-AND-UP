

int insertion_sort(int *a, int n){
	int i=1;
	int j=i;
	int t;
	for(i=1; i<n; ++i){
		for(j=0; j<i; ++j){
			if(a[i]<a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	return 0;
}
