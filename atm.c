/*
 * atm.c
 * Bir kullanicinin hesabini gosteren bir atm programi
 * Büşra Karaca
 * Ogrenci No : 20120101019
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>	/*Sleep fonksiyonunun icinde bulundugu kutuphane*/
 
 const int PSWRD = 1234;       /*Musterinin sifresi*/
 const int bakiye = 100; 	/*Musterinin baslangic bakiyesi*/
 
int main(){
	
	 int sifre;
	 int islem;
	 int guncel_bakiye;
	 int tutar; 
	 int hatali_giris =0;
	 
		printf("Merhaba C bankaniza hosgeldiniz.\n");   	  /*Programa baslangic cumlesi*/
		printf("Lutfen sifrenizi giriniz: ");		 /*Kullanicidan sifre istenir.*/
	    	scanf("%i" ,&sifre);				/*Kullanicidan sifreyi alir ve sifre degiskenine atar.*/
	 
	 while( sifre != PSWRD && hatali_giris < 2 ){		/*Sifre yanlis girildiginde while dongusune girer.*/
		 
			if( sifre != PSWRD){							
		 printf("Hatali sifre girdiniz. %i deneme hakkiniz kaldi.\n",2-hatali_giris);		/*Sifrenin hatali oldugunu belirtir.*/
		 hatali_giris++;							          
		 printf("Lutfen sifrenizi tekrardan giriniz: ");	  /*Tekrardan sifre sorar.*/
		 scanf("%i" ,&sifre); 							
	     }
		 
			if( hatali_giris == 3){			   /*Sifre 3 kere hatali girildiginde sistem hata verir.*/
				printf("Hatali sifre girdiginizden dolayi isleminiz kisitlanmistir. Iyi gunler.\n");      /*Program sonlanir.*/
				sleep(2);			   /*2 saniye sonra programdan cikar.*/
				return 0;
			}
	 }
	 
	 if(sifre == PSWRD){					/*Kullanicinin girdigi sifre PSWRD ile aynıysa*/
			printf("Sifre dogru.\nIslemler sayfasina yonlendiriliyorsunuz...\n\n");
			sleep(2);				/*2 saniye sonra diger ifadeyi yazdirir.*/
		}
	
	 while( sifre == PSWRD){        				/*Sifre dogru girildiginde bu donguye girer.*/
		
		printf("\nIslemler:\n1:Para Yatirma\n2:Para Cekme\n3:Hesap Bakiyesini Goruntuleme\n4:Cikis\n\n");		/*Atmdeki islemleri yazar.*/
		printf("Yapacaginiz islemi seciniz: ");		/*Kullanicidan islem numarasi secmesi istenir.*/
		scanf("%i" ,&islem);				/*Kullanicinin girdigi numara islem degiskenine atanir.*/
		
			
	 switch(islem){
		
		case 1:						/*Para yatirma islemi*/
		
			printf("\nLutfen miktari giriniz: ");	 	/*Kullanicidan yatirmak istenen tutar alinir.*/
			scanf("%i" ,&tutar);						
			
			if(tutar > 0){				/*Tutar eger pozitif sayi ise*/
				printf("Para hesabiniza yatiriliyor...\nLutfen bekleyiniz...\n\n");
				sleep(3);				/*3 saniye sonra diger ifadeyi yazdirir.*/
			    guncel_bakiye = bakiye + tutar;
				printf("Isleminiz basariyla gerceklestirildi.\n");
				printf("Yeni bakiyeniz %i TL dir.\nAna sayfaya yonlendiriliyorsunuz...\n",guncel_bakiye);		/*Kullanicinin yeni bakiyesi ekrana yazdirilir.*/
				sleep(2);				/*2 saniye sonra diger ifadeyi yazdirir.*/
			}
			
			else 					/*Tutar negatif bir sayi girildiyse else ifadesine girer.*/
				printf("Hatali tutar girisi. Islem basarisiz.\n"); 
				sleep(2);				/*2 saniye sonra ana sayfaya doner.*/
			break;
		
		case 2:					    	/*Para cekme islemi*/
		
			printf("\nLutfen miktari giriniz: ");		/*Kullanicidan cekmek istedigi tutar alinir.*/
			scanf("%i" ,&tutar);
			
			if( tutar > 0 && tutar < bakiye){		/*Tutar pozitif sayi ve bakiyeden az ise*/
				printf("Para hesabinizdan cekiliyor...\nLutfen bekleyiniz...\n\n");
				sleep(3);				/*3 saniye sonra diger ifadeyi yazdirir.*/
				guncel_bakiye = bakiye - tutar;
				printf("Isleminiz basariyla gerceklestirildi.\n");
				printf("Yeni bakiyeniz %i TL dir.\nAna sayfaya yonlendiriliyorsunuz...\n",guncel_bakiye);		/*Kullanicinin yeni bakiyesi ekrana yazdirilir.*/
				sleep(2);				/*2 saniye sonra ana sayfaya doner.*/
			}
			
			else if(tutar < 0){				/*Tutarin negatif sayi olmasi durumunda asagidaki ifadeyi yazdirir.*/
				printf("Hatali giris. Islem basarisiz.\nAna sayfaya yonlendiriliyorsunuz...\n");
				sleep(2);				/*2 saniye sonra ana sayfaya doner.*/
			}
				
			else if(tutar > bakiye){			/*Cekilecek tutarin bakiyeden fazla olmasi durumunda asagidaki ifadeyi yazdirir.*/
				printf("Bakiyeniz yetersizdir.\nAna sayfaya yonlendiriliyorsunuz...\n");
				sleep(2);				/*2 saniye sonra ana sayfaya doner.*/
			}
			break;	
		
		case 3:						/*Bakiye sorgulama*/
		
			printf("\nHesap bakiyeniz %i TL dir.\nAna sayfaya yonlendiriliyorsunuz...\n",guncel_bakiye);      	/*Guncel hesap bakiyesi ekrana yazdirilir.*/                           
			sleep(2);					/*2 saniye sonra ana sayfaya doner.*/
			break;
		
		
		case 4:						/*Kart iade*/
		
			printf("\nKartiniz iade ediliyor...\n");
			sleep(3);					/*3 saniye sonra diger ifadeyi yazdirir.*/
			printf("Bizi tercih ettiginiz icin tesekkurler.Yine bekleriz.\n");		/*Tesekkurler mesaji*/
			sleep(2);					/*2 saniye sonra programdan cikar.*/
			return 0;
		
		default :						/*Gecersiz bir islem numarasi girildiginde kullanilir.*/
		
			printf("\nLutfen gecerli bir islem numarasi giriniz.Ana sayfaya yonlendiriliyorsunuz...\n");	/*Ekrana yazdirir.*/
			sleep(2);					/*2 saniye sonra ana sayfaya doner.*/
			break;
	}
	}
		return 0;
}

