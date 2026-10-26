
#include <stdio.h>
#include <string.h>

struct GiaoDich {
    int loai;
    char noiDung[100];
    float soTien;
    int thang;
    int nam;
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
    
    printf("Nhap thang giao dich: ");
    if(scanf("%d",&ds[n].thang) != 1 ) {
    	printf("Nhap sai du lieu!\n");
    	return;
	}
	
	printf("Nhap nam giao dich: ");
	if(scanf("%d",&ds[n].nam) != 1 ) {
		printf("Nhap sai du lieu!\n");
		return;
	}
	
	if(ds[n].nam <1900 || ds[n].nam > 2100) {
		printf("Nam khong hop le!\n");
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
        printf("thang/nam: %02d/%d\n",ds[n].thang,ds[n].nam);
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

void thongKeThang(){
	int thangCanTim;
	int namCanTim;
	int soGiaoDich = 0;
	double tongThu = 0;
	double tongChi = 0;
	double chenhLech;
	
	printf("\n--- THONG KE THEO THANG ---\n");
	printf("Nhap thang can thong ke: ");
	
	if(scanf("%d",&thangCanTim) != 1 ){
		printf("Nhap sai du lieu!\n");
		return;
	}
	printf("Nhap Nam can thong ke: ");
	
	if(scanf("%d",&namCanTim) != 1){
		printf("Nhap sai du lieu!\n");
		return;
	}
	
	if(namCanTim < 1900 || namCanTim> 2100){
		printf("Nam khong hop le!\n");
		return;
	}
	
	for (int i = 0;i < n; i++){
	if(ds[i].thang == thangCanTim && ds[i].nam == namCanTim){
		soGiaoDich++;
		
		if(ds[i].loai == 1){
			tongThu= tongThu + ds[i].soTien;
		} else {
			tongChi = tongChi + ds[i].soTien;
		}
	}
}

	chenhLech = tongThu - tongChi;
	printf("\nThong ke thang %02d/%d\n",thangCanTim,namCanTim);
	printf("So giao dich: %d\n",soGiaoDich);
	printf("Tong thu: %.2f\n",tongThu);
	printf("Tong chi: %.2f\n",tongChi);
	printf("Chenh lech trong thang: %.2f VND\n",chenhLech);
}

void timGiaoDich(){
	char tuKhoa[100];
	int soKetQua = 0;
	
	printf("\n--- TIM KIEM GIAO DICH ---\n");
	printf("Nhap tu khoa can tim:");
	if(scanf(" %99s[^\n]",tuKhoa) != 1){
		printf("Nhap sai noi dung!\n");
		return;
	}
	for (int i = 0;i<n;i++){
		if(strstr(ds[i].noiDung,tuKhoa)!= NULL){
			soKetQua++;
			printf("\nGiao dich %d\n",i + 1);
			if(ds[i].loai == 1){
				printf("Loai: Thu\n");
			} else {
				printf("Loai: Chi\n");
			}
			printf("Noi dung: %s\n",ds[i].noiDung);
			printf("So tien: %.2f VND\n",ds[i].soTien);
			printf("Thang/nam: %02d/%d\n",ds[i].thang,ds[i].nam);
			}
		}
		if(soKetQua == 0 ){
			printf("Khong tim thay giao dich.\n");
		} else{
			printf("\nTim thay %d giao dich\n",soKetQua);
		}
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
        printf("4. Thong ke thu chi theo thang\n");
        printf("5. Tim kiem giao dich\n");
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
            case 4:
            	thongKeThang();
            	break;
            case 5:
            	timGiaoDich();
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

