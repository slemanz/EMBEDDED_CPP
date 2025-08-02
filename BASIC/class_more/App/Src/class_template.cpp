#include "mcal_reg.h"
#include "uart.h"

template <class T>

class dataStatistics
{
    private:
        T data[7];
        int capacity;
    
    public:
        dataStatistics();
        dataStatistics(T d[])
        {
            for(int i = 0; i < 7; i++)
            {
                data[i] = d[i];
            }
        }

        float computeMean();
        T findMax();
        int searchValue(T val);
        T findMode();
};

template <class T>
float dataStatistics<T>::computeMean()
{
    // run mean algo
    return 0.0;
}

template <class T>
T dataStatistics<T>::findMax()
{
    T mx = data[0];
    for(int i = 0; i < 7; i++)
    {
        if(mx < data[i])
        {
            mx = data[i];
        }
    }
    return mx;
}

template <class T>
T dataStatistics<T>::findMode()
{
    return 0.0;
}

template <typename T>
int dataStatistics<T>::searchValue(T val)
{
    return 0;
}


int main(void)
{
    uart_init();
    printf("Init the board!\n");


    float f_values[] = {0.1, 0.2, 0.9, 0.8, 0.11, 0.34, 0.78};
    int i_values [] = {7, 8, 3, 4, 6, 7, 0};

    dataStatistics<float> f_dataset(f_values);
    dataStatistics<int> i_dataset(i_values);

    printf("The maximum vlaue in the dataset is %f \n", f_dataset.findMax());
    printf("The maximum vlaue in the dataset is %d \n", i_dataset.findMax());

    while(1)
    {
        
    }
}

