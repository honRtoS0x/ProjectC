
#include <stdio.h>

struct GiaoDich {
    int loai;
    char noiDung[100];
    float soTien;
};

struct GiaoDich ds[100];
int n = 0;

void themGiaoDich() {
    if (n >= 100) {
        printf("Danh sach da day!\n");
        return;
    }

    printf("\n--- THEM GIAO DICH ---\n");
    printf("1. Thu\n");
    printf("2. Chi\n");
    printf("Chon loai: ");

    if (scanf("%d", &ds[n].loai) != 1) {
        printf("Nhap sai loai!\n");
        return;
    }

    if (ds[n].loai != 1 && ds[n].loai != 2) {
        printf("Loai khong hop le!\n");
        return;
    }

    printf("Nhap noi dung: ");
    scanf(" %99[^\n]", ds[n].noiDung);

    printf("Nhap so tien: ");
    if (scanf("%f", &ds[n].soTien) != 1) {
        printf("Nhap sai so tien!\n");
        return;
    }

    if (ds[n].soTien <= 0) {
        printf("So tien khong hop le!\n");
        return;
    }

    n++;
    printf("Them giao dich thanh cong!\n");
}

void xemGiaoDich() {
    printf("\n--- DANH SACH GIAO DICH ---\n");

    if (n == 0) {
        printf("Chua co giao dich!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nGiao dich %d\n", i + 1);

        if (ds[i].loai == 1) {
            printf("Loai: Thu\n");
        } else {
            printf("Loai: Chi\n");
        }

        printf("Noi dung: %s\n", ds[i].noiDung);
        printf("So tien: %.2f VND\n", ds[i].soTien);
    }
}

void tinhTong() {
	double tongThu = 0;
	double tongChi = 0;
	double soDu;
	
	for (int i = 0; i < n; i++){
		if(ds[i].loai == 1){
			tongThu = tongThu + ds[i].soTien;
		} else {
			tongChi = tongChi + ds[i].soTien;
		}
	}
	soDu = tongThu - tongChi;
	printf("\n--- TONG THU/ CHI ---\n");
	printf("Tong thu: %.2f VND\n",tongThu);
	printf("Tong chi: %.2f VND\n",tongChi);
	printf("So du con lai: %.2f VND\n",soDu);
}
int main() {
    int chon;

    do {
        printf("\n========================\n");
        printf("    QUAN LY THU CHI\n");
        printf("========================\n");
        printf("1. Them giao dich\n");
        printf("2. Xem danh sach\n");
        printf("3. Tong thu, tong chi va so du\n");
        printf("0. Thoat\n");
        printf("------------------------\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chon) != 1) {
            printf("Nhap sai du lieu!\n");
            return 0;
        }

        switch (chon) {
            case 1:
                themGiaoDich();
                break;
            case 2:
                xemGiaoDich();
                break;
            case 3:
            	tinhTong();
            	break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}

