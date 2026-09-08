int main(){
    int arr[]= {1,2,5,3,1,2,3,4,6};
    int size = 9;

    for(int i=0; i<size; i++){
        int count=0;

        for(int j=0; j<size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count == 1){
            cout << arr[i] << " ";
        }
    }

    return 0;
}