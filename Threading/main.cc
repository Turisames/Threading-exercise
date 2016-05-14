#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include <QCoreApplication>

static const int NUM_THREADS = 10;
static std::mutex barrier;

void
helloWorld()
{
    std::cout << "Hello, girls!" << std::endl;
}

void
launchedFromThread( int i )
{
    std::cout << "Tämä tulee säikeestä " << i << std::endl;
}

void
dot_product_nonparallel(const std::vector<int> &v1,
            const std::vector<int> &v2,
            int &result, int L, int R)
{
    for(int i = L; i < R; ++i){
        result += v1[i] * v2[i];
    }
}

void
dot_product(const std::vector<int> &v1,
            const std::vector<int> &v2,
            int &result, int L, int R)
{
    int partial_sum = 0;

    for(int i = L; i < R; ++i){
        partial_sum += v1[i] * v2[i];
    }
    std::lock_guard< std::mutex > block_threads_until_finished ( barrier ) ;
    result += partial_sum;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    /*
    //std::thread t[ NUM_THREADS ];
    std::vector<std::thread> th;

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        //t[i] = std::thread( launchedFromThread, i );
        th.push_back( std::thread( launchedFromThread, i ) );
    }

    std::cout << "Launched from main" << std::endl;

    for (auto &t : th)
    {
        t.join();
    }
    /*for (int i = 0; i < NUM_THREADS; ++i)
    {
        //t[i].join();

    }//*/
    //*/

    int nr_elements = 100000;
    int nr_threads = 2;
    int result = 0;
    std::vector<std::thread> threads;

    //Fill two vectors with some constant values for a quick verification
    // v1={1,1,1,1,...,1}
    // v2={2,2,2,2,...,2}
    // The result of the dot_product should be 200000 for this particular case
    std::vector<int> v1(nr_elements,1), v2(nr_elements,2);

    //Split nr_elements into nr_threads parts
    std::vector<int> limits = bounds( nr_threads, nr_elements );

    //Launch nr_threads threads:
    for (int i = 0; i < nr_threads; ++i) {
        threads.push_back(std::thread(dot_product, std::ref(v1), std::ref(v2), std::ref(result), limits[i], limits[i+1]));
    }


    //Join the threads with the main thread
    for(auto &t : threads){
        t.join();
    }

    //Print the result
    std::cout<<result<<std::endl;

    return a.exec();
}
