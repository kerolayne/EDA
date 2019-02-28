void selectionSort(int v[], int tamanho){
	int i;
	for(i = 0; i < tamanho - 1; i++){
		int i_menor = i;
		int j;
		for(j = i+1; j < tamanho; j++){
			if(v[j] < v[i_menor])
			i_menor = j;
		}
		int temp = v[i];
		v[i] = v[i_menor];
		v[i_menor] = temp;
 	}
}
