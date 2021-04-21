#include <stdio.h>
#include <math.h>

float odleglosc(float x1, float y1, float x2, float y2);
float cosinus(float odleglosc_srodkow, float r1, float r2); 
float sinus(float cos);

int main(){
    
    float x1, y1, r1;
    float x2, y2, r2;

    printf("Podaj wspolrzedne srodka i promien pierwszego okregu (x y r):\n");
    scanf("%f %f %f", &x1, &y1, &r1);
    
    printf("Podaj wspolrzedne srodka i promien drugiego okregu (x y r):\n");
    scanf("%f %f %f", &x2, &y2, &r2);
        
    float odleglosc_srodkow = odleglosc(x1, y1, x2, y2);
    
    if (r1 == 0 || r2 == 0)
    {
        printf("Promien nie moze byc rowny 0\n");
    }
    
    else
    {
        if (odleglosc_srodkow < fabsf(r1 - r2))
        {
            printf("Okregi rozlaczne wewnetrznie\n");
        }
        
        else if (odleglosc_srodkow > r1 + r2)
        {
            printf("Okregi rozlaczne zewnetrznie\n");
        }
        
        else if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            printf("Okregi rowne\n");
        }
        
        else
        {
            float cos = cosinus(odleglosc_srodkow, r1, r2);
            float sin = sinus(cos);
            
            float x_wektora_pomocniczego = (x2 - x1) * r1/odleglosc_srodkow;
            float y_wektora_pomocniczego = (y2 - y1) * r1/odleglosc_srodkow;
            
            float x_pierwszego_punktu = x_wektora_pomocniczego * cos - y_wektora_pomocniczego * sin + x1;
            float y_pierwszego_punktu = x_wektora_pomocniczego * sin + y_wektora_pomocniczego * cos + y1;
            float x_drugiego_punktu = x_wektora_pomocniczego * cos + y_wektora_pomocniczego * sin + x1;
            float y_drugiego_punktu = -x_wektora_pomocniczego * sin + y_wektora_pomocniczego * cos + y1;
            
            /*printf("\ncosx = %f\n", cos);
            printf("sinx = %f\n", sin);
            printf("vp = [%f, %f]\n\n", x_wektora_pomocniczego, y_wektora_pomocniczego);
            */
            
            if (odleglosc_srodkow == r1 + r2)
            {
                printf("Okręgi styczne\nP = (%f,%f)\n", x_pierwszego_punktu, y_pierwszego_punktu);
            }
            
            else
            {
                printf("\nP1 = (%f,%f)\nP2 = (%f,%f)\n", x_pierwszego_punktu, y_pierwszego_punktu, x_drugiego_punktu, y_drugiego_punktu);
            }
        }
    }
    return 0;
}



float odleglosc(float x1, float y1, float x2, float y2)
{
    
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float cosinus(float odleglosc_srodkow, float r1, float r2)
{
    
    return (odleglosc_srodkow * odleglosc_srodkow + r1 * r1 - r2 * r2) / (2 * odleglosc_srodkow * r1);
}

float sinus(float cos)
{
    return sqrt(1 - cos * cos);
}
