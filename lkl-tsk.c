#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAME_LENGTH 50
#define NIM_LENGTH 8

void operation_menu();
void operation_determiner();
void operation_processor(int code);

void add_data();
void show_all_data();
void show_data_by_nim();
void update_data_by_name();
void delete_data();

void ginps(char message[], char *obj, int mxvl);
void ginpsc(char message[], char *obj);
void float_input(char *message, float *object);
float get_fs();
char get_hm(float fs);

struct student_node
{
    char name[NAME_LENGTH+1], nim[NIM_LENGTH+1], ql;
    float quiz_score, task_score, uts_score,
        uas_score, final_score;
    struct student_node *next_node;
};

struct student_node *head_ptr = NULL;

// Driver program

int main()
{
    operation_menu();
    return 0;
}

// Operation Flow

void operation_menu() 
{
    puts("");
    puts("Pilih operasi yang akan dilakukan :");
    puts("1. Menambahkan data Mahasiswa");
    puts("2. Menampilkan seluruh data Mahasiswa");
    puts("3. Menampilkan data berdasarkan NIM");
    puts("4. Mengubah data berdasarkan nama");
    puts("5. Menghapus data");
    puts("6. Keluar");
    puts("");
    operation_determiner();
}

void operation_determiner()
{
    short int opt;
    printf("Pilihan: "); 
    scanf("%hd", &opt);
    puts("");
    operation_processor(opt);
}

void operation_processor(int code)
{
    switch(code) {
        case 1 : 
        {
            add_data();
            break;
        }
        case 2 : 
        {
            show_all_data();
            break;
        }
        case 3 : 
        {
            show_data_by_nim();
            break;
        }
        case 4 : 
        {
            update_data_by_name();
            break;
        }
        case 5 : 
        {
            delete_data();
            break;
        }
        case 6 : 
        {
            puts("Keluar.");
            exit(1);
            break;
        }
        default : 
        {
            puts("Pilihan tidak valid!!");
            puts("Ulangi pemasukan\n");
            operation_determiner();
            break;
        }
    }
}

// Implementation function

void add_data() 
{
    char answer;
    struct student_node *new_ptr;

    puts("Menabahkan data baru");

    do
    {

        new_ptr = (struct student_node *)malloc(sizeof(struct student_node));

        if (new_ptr)
        {
            ginps("Nama     : ", new_ptr->name, NAME_LENGTH);
            ginpsc("NIM       : ", new_ptr->nim);
            float_input("Nilai Tugas : ", &new_ptr->task_score);
            float_input("Nilai Quiz : ", &new_ptr->quiz_score);
            float_input("Nilai UTS : ", &new_ptr->uts_score);
            float_input("Nilai UAS : ", &new_ptr->uas_score);

            printf("%.2f", new_ptr->task_score);
            printf("name %s", new_ptr->name);
        }
        else
        {
            puts("Memori tidak cukup..!");
        }

        printf("Masukkan data lagi? (Y/T) = ");
        scanf(" %c", &answer);

    } while (answer == 'Y');

    operation_menu();
}

void show_all_data()
{
    puts("should show all data");
    operation_menu();
}

void show_data_by_nim()
{
    puts("should show single data");
    operation_menu();
}

void update_data_by_name()
{
    puts("should update data");
    operation_menu();
}

void delete_data()
{
    puts("should delete data");
    operation_menu();
}

// Helper function

void ginps(char message[], char *obj, int mxvl)
{
    char c; int i = 0, end = 0;
    printf("%s", message);
    do
    {
        c = getchar();
        if (c == '\n' || i > mxvl)
        {
            end++;
        }
        else
        {
            obj[i] = c;
            i++;
        }
    }
    while (end == 1);
}

void ginpsc(char message[], char *obj)
{
    printf("%s", message);
    scanf("%s", obj);
}

void float_input(char *message, float *object)
{
    printf("%s", message);
    scanf("%f", object);
}

float get_fs()
{

}

char get_hm(float fs)
{

}
