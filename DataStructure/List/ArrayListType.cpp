#include <cstdio>
#include <cstdlib>
#define MAX_LIST_SIZE 100   // 리스트의 최대크기

typedef int element;    // 항목의 정의

typedef struct 
{
    element array[MAX_LIST_SIZE];
    int size;    
} ArrayListType;

// 오류 처리 함수
void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L){
    L->size = 0;
}

// 리스트 비어있으면 1, 아니면 0 반환
int is_empty(ArrayListType *L){
    return L->size == 0;
}

// 리스트가 가득차있으면 1 반환, 아니면 0 반환
int is_full(ArrayListType *L){
    return L->size == MAX_LIST_SIZE;
}

// 접근이 가능한지 확인
element get_entry(ArrayListType *L, int pos){
    // out of range
    if(pos < 0 || pos >= L->size)
        error("out of range");
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType *L){
    int i=0;
    for(i=0; i < L->size; i++){
        printf("%d ", L->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *L, element item){
    if(L->size >= MAX_LIST_SIZE)
        error("리스트 오버플로우");
    L->array[L->size++] = item;
}

// 리스트 요소 삽입
void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L) && (pos>=0) &&(pos <= L->size)){
        for(int i = (L->size-1); i>=pos; i--)
            L->array[i + 1] = L->array[i];
        L->array[pos] = item;
        L->size++;
    }
}

// 요소 삭제
element delete_element(ArrayListType *L, int pos){
    element item;

    if(pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->array[pos];
    for(int i = pos; i<(L->size -1); i++)
        L->array[i] = L->array[i+1];
    L->size--;
    return item;
}

void clear(ArrayListType *L){
    for(int i=0; i<L->size; i++){
        L->array[i] = 0;
    }
    L->size = 0;
}

void replace(ArrayListType *L, int pos, element item){
    L->array[pos] = item;
}

int get_length(ArrayListType *L){
    return L->size;
}
int main(){
    ArrayListType list;
    init(&list);
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete_element(&list, 0); print_list(&list);
    clear(&list); print_list(&list);
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    printf("length:%d", get_length(&list));
    replace(&list, 2, 30); print_list(&list);
    printf("length:%d", get_length(&list));
    return 0;
}




