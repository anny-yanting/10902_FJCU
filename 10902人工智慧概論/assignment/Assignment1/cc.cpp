#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

int direction(int x_target, int y_target)
{
    int action;
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;

    return action;
}
__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
    int selfx = xCoordinate[0]; //ball 1's xCoordinate
    int selfy = yCoordinate[0]; //ball 1's yCoordinate
    int location = 10; //first black ball's location
    bool flag = false;
    int maximum_blackball = 5; //assume the biggest black ball that ball 1 need to catch

    // find the biggest black ball and return its locatin
    for(size_t i = 10; i < 15; i++){
        if(circleRadius[i] > 0 && circleRadius[i] >= maximum_blackball){
            maximum_blackball = circleRadius[i];
            location = i;
            flag = true;
        }
    }
    int maximum_ball = 0;
    // if the black ball's radius are all smaller than 5, and the target turn to the ball which is smaller than ball 1 and the biggest in ball 2 to ball 10;
    if(!flag){
        for(size_t i = 10; i < 15; i++){
            if(circleRadius[i] < 5){
                for(size_t t = 1; t < 10; t++){
                    if(circleRadius[t] < circleRadius[0] && circleRadius[t] > 0 && circleRadius[t] > maximum_ball){
                        maximum_ball = circleRadius[t];
                        location = t;
                        break;
                    }
                }
            }
        }
    }

    // find the target in the which side of ball 1
    int x_target = xCoordinate[location] - selfx;
    int y_target = yCoordinate[location] - selfy;
    // decide the direction
    action = direction(x_target, y_target);

    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

===================================================================================================
int selfx = xCoordinate[0];
    int selfy = yCoordinate[0];
    int x = selfx - xCoordinate[*min_element(circleRadius , circleRadius + sizeof(circleRadius))];
    int y = selfy - yCoordinate[*min_element(circleRadius , circleRadius + sizeof(circleRadius))];

    if(x == 0 && y > 0)
        action = UP;
    else if(x == 0 && y < 0)
        action = DOWN;
    else if(x > 0 && y == 0)
        action = RIGHT;
    else if(x < 0 && y == 0)
        action = LEFT;
    else if(x > 0 && y > 0)
    	action = UP_RIGHT;
    else if(x > 0 && y < 0)
    	action = DOWN_RIGHT;
    else if(x < 0 && y > 0)
    	action = UP_LEFT;
    else if(x < 0 && y < 0)
    	action = DOWN_LEFT;


    Sleep(500);
    return;

    if(x == 0 && y > 0)
        action = UP;
    else if(x == 0 && y < 0)
        action = DOWN;
    else if(x > 0 && y == 0)
        action = RIGHT;
    else if(x < 0 && y == 0)
        action = LEFT;
    else if(x > 0 && y > 0)
    	action = UP_RIGHT;
    else if(x > 0 && y < 0)
    	action = DOWN_RIGHT;
    else if(x < 0 && y > 0)
    	action = UP_LEFT;
    else if(x < 0 && y < 0)
    	action = DOWN_LEFT;

    if(x == 0 && y > 0)
        action = DOWN;
    else if(x == 0 && y < 0)
        action = UP;
    else if(x > 0 && y == 0)
        action = RIGHT;
    else if(x < 0 && y == 0)
        action = LEFT;
    else if(x > 0 && y > 0)
    	action = DOWN_RIGHT;
    else if(x > 0 && y < 0)
    	action = UP_RIGHT;
    else if(x < 0 && y > 0)
    	action = DOWN_LEFT;
    else if(x < 0 && y < 0)
    	action = UP_LEFT;





    //freopen("log1.txt", "a+", stdout);
    int selfx = xCoordinate[0];
    int selfy = yCoordinate[0];
    //find the smallest black ball's location
    int x_target = xCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfx; // find the target's xCoordinate
    int y_target = yCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfy; // find the target's yCoordinate

    //where the ball go ?
    if(x_target == 0 && y_target > 0) //the target ball is above  
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under 
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right 
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left 
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;
    //fclose(stdout);
    //Sleep(500);

    return;


=============================================================================================
    freopen("log1.txt", "a+", stdout);
    int selfx = xCoordinate[0];
    int selfy = yCoordinate[0];
    //find the smallest black ball's location
    //int x_target = xCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfx; // find the target's xCoordinate
    //int y_target = yCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfy; // find the target's yCoordinate
    int location = 10;

     for(size_t i = 0; i < 15; i++){
        printf("i = %d; circleRadius = %d; xCoordinate = %d; yCoordinate = %d; xVelocity = %d; yVelocity[i] = %d\n", i, circleRadius[i], xCoordinate[i], yCoordinate[i], xVelocity[i], yVelocity[i]);
    }
    printf("location is %d\n", location);


    for(size_t i = 10; i < num_resources; i++){
        int minimum = 200;
        printf("i am enter for loop\n");
        if(circleRadius[i] > 0 && circleRadius[i] <= minimum){
            printf("i am enter if loop\n");
            minimum = circleRadius[i];
            location = i;
        }
    }

    int x_target = xCoordinate[location] - selfx; // find the target's xCoordinate
    int y_target = yCoordinate[location] - selfy; // find the target's yCoordinate
    //where the ball go ?
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;
    fclose(stdout);
    //Sleep(500);

    return;


















=====================================================================================================
#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
    //freopen("log1.txt", "a+", stdout);
    int selfx = xCoordinate[0];
    int selfy = yCoordinate[0];
    //find the smallest black ball's location
    //int x_target = xCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfx; // find the target's xCoordinate
    //int y_target = yCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfy; // find the target's yCoordinate
    int location = 10;
    for(size_t i = 0; i < 15; i++){
        printf("i = %d; circleRadius = %d;\n", i, circleRadius[i]);
    }
    puts("");
    int maximum = 5;
    for(size_t i = 10; i < 15; i++){
        if(circleRadius[i] > 0 && circleRadius[i] >= maximum){
            maximum = circleRadius[i];
            location = i;
            printf("location is %d; i = %d\n", location, i);
            break;
        }
        if(circleRadius[i] == 0 && circleRadius[i] < circleRadius[0]){
            for(size_t t = 1; t < 10; t++){
                if(circleRadius[t] < circleRadius[0] && circleRadius[t] > 0){
                    location = t;
                    continue;
                }
            }
        }
    }
    printf("max = %d;  location is %d\n", maximum, location);
    int x_target = xCoordinate[location] - selfx; // find the target's xCoordinate
    int y_target = yCoordinate[location] - selfy; // find the target's yCoordinate
    //where the ball go ?
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;
    //fclose(stdout);

    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

====================================================
#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
    //freopen("log1.txt", "a+", stdout);
    int selfx = xCoordinate[0];
    int selfy = yCoordinate[0];
    //find the smallest black ball's location
    //int x_target = xCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfx; // find the target's xCoordinate
    //int y_target = yCoordinate[10 + *min_element(circleRadius + 10 , circleRadius + 10 + num_resources)] - selfy; // find the target's yCoordinate
    int location = 10;
    for(size_t i = 0; i < 15; i++){
        printf("i = %d; circleRadius = %d;\n", i, circleRadius[i]);
    }
    puts("");
    //int maximum = 0;
    int time = 0;
    vector<int> v;
    for(size_t i = 10; i < 15; i++){
        if(circleRadius[i] > 0){
            for(size_t j = 0; j < 10; j++){
                int x_length = (circleRadius[i] - circleRadius[j]) * (circleRadius[i] - circleRadius[j]);
                int y_length = (circleRadius[i] - circleRadius[j]) * (circleRadius[i] - circleRadius[j]);
                int target_distance = sqrt(x_length + y_length);
                int x_speed = xVelocity[i] * xVelocity[i];
                int y_speed = yVelocity[i] * yVelocity[i];
                int speed = sqrt(x_speed + y_speed);
                time = (target_distance) / speed;
                v.push_back(time);
            }
            for(size_t k = 0; k < 10; k++){
                if(v[k] > v[0]){
                    location = i;
                    break;
                }
            }
            //maximum = circleRadius[i];
            //location = i;
            //break;
        }
        if(circleRadius[i] == 0 && circleRadius[i] < circleRadius[0]){
            for(size_t t = 1; t < 10; t++){
                if(circleRadius[t] < circleRadius[0] && circleRadius[t] > 0){
                    location = t;
                    continue;
                }
            }
        }
    }
    //printf("max = %d;  location is %d\n", maximum, location);
    int x_target = xCoordinate[location] - selfx; // find the target's xCoordinate
    int y_target = yCoordinate[location] - selfy; // find the target's yCoordinate
    //where the ball go ?
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;
    //fclose(stdout);

    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
===============================================================================



#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
   
	int selfx = xCoordinate[0];
	int selfy = yCoordinate[0];
	action = DOWN_RIGHT;
	if(xCoordinate[0] + circleRadius[0] == 1600 && yCoordinate[0] + circleRadius[0] == 900)
		action = UP_LEFT;
	else if(xCoordinate[0] - circleRadius[0] == 0 && yCoordinate[0] - circleRadius[0] == 0)
		action = RIGHT;
	else if (xCoordinate[0] + circleRadius[0] == 1600 && yCoordinate[0] + circleRadius[0] == 0)
		action = DOWN_LEFT;
	else if (xCoordinate[0] + circleRadius[0] == 0 && yCoordinate[0] + circleRadius[0] == 900)
		action = RIGHT;

    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}







	int action;
    if(selfx > x && selfy > y)
        action = UP_LEFT;
    else if(selfx> x && selfy < y)
        action = DOWN_LEFT;
    else if(selfx< x && selfy < y)
        action = DOWN_RIGHT;
    else if(selfx< x && selfy > y)
        action = UP_RIGHT;
    else if(selfx== x && selfy < y)
        action = DOWN;
    else if(selfx== x && selfy > y)
        action = UP;
    else if(selfx> x && selfy == y)
        action = LEFT;
    else if(selfx< x && selfy == y)
        action = RIGHT;
    return action;

================== MIMMY CODE
#include "agent_dll.h"
#include <bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };
int xCoordinate[20], yCoordinate[20];
#ifdef __cplusplus
extern "C"
{
#endif

int find(int xs, int ys,int x, int y)
{
    int action;
    if(xs > x && ys > y) action = UP_LEFT;
    else if(xs> x && ys < y) action = DOWN_LEFT;
    else if(xs< x && ys < y) action = DOWN_RIGHT;
    else if(xs< x && ys > y) action = UP_RIGHT;
    else if(xs== x && ys < y) action = DOWN;
    else if(xs== x && ys > y) action = UP;
    else if(xs> x && ys == y) action = LEFT; 
    else if(xs< x && ys == y) action = RIGHT;
    return action;
}
__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{

    int minn = 4810500;
    int loc = 0;
    for(int i = 1; i <= 14; i++) //查所有球球的大小
    {
        if(circleRadius[i] < circleRadius[0])//當半徑比我小時
        {
            int ad = 0;// 利益值
            ad = (xCoordinate[i] - xCoordinate[0]) * (xCoordinate[i] - xCoordinate[0]) + (yCoordinate[i] - yCoordinate[0]) * (yCoordinate[i] - yCoordinate[0]) + (200 - circleRadius[i]) * (200 - circleRadius[i])*100;
            // 考慮距離，和半徑大小，但半徑的數值比距離小，所以乘100
            if(ad < minn)
            {
                minn = ad;
                loc = i;
            }
        }
    }
    action = find(xCoordinate[0], yCoordinate[0],xCoordinate[loc], yCoordinate[loc]);

    return ;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}


=======================================================

#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

int direction(int x_target, int y_target)
{
    int action;
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
    	action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
    	action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
    	action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
    	action = UP_LEFT;

    return action;
}
__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
    int selfx = xCoordinate[0]; //ball 1's xCoordinate
    int selfy = yCoordinate[0]; //ball 1's yCoordinate
    int location = 10; //first black ball's location
    bool flag = false;
    int maximum_blackball = 5; //assume the biggest black ball that ball 1 need to catch
    int min_distance = 800;
    // find the biggest black ball and the closest, return its location
    for(size_t i = 10; i < 15; i++){
        int x_distance = (xCoordinate[i] - xCoordinate[0]) * (xCoordinate[i] - xCoordinate[0]);
        int y_distance = (yCoordinate[i] - yCoordinate[0]) * (yCoordinate[i] - yCoordinate[0]);
        int two_distance = sqrt(x_distance + y_distance);
        if(circleRadius[i] > 0 && circleRadius[i] >= maximum_blackball && two_distance < min_distance ){
            maximum_blackball = circleRadius[i];
            min_distance = two_distance;
            location = i;
            flag = true;
        }
    }
    int maximum_ball = 0;
    int mini_distance = 1600;
    // if the black ball's radius are all smaller than 5, and the target turn to the ball which is smaller a than ball 1 and the closest and the biggest in ball 2 to ball 10;
    if(!flag){
        for(size_t i = 10; i < 15; i++){
            if(circleRadius[i] < 5){

                int x_distance = (xCoordinate[i] - xCoordinate[0]) * (xCoordinate[i] - xCoordinate[0]);
                int y_distance = (yCoordinate[i] - yCoordinate[0]) * (yCoordinate[i] - yCoordinate[0]);
                int two_distance = sqrt(x_distance + y_distance);
                for(size_t t = 1; t < 10; t++){
                    if(circleRadius[t] < circleRadius[0] && circleRadius[t] > 0 && circleRadius[t] > maximum_ball && two_distance < mini_distance ){
                        maximum_ball = circleRadius[t];
                        min_distance = two_distance;
                        location = t;
                        break;
                    }
                }
            }
        }
    }

    // find the target in the which side of ball 1
    int x_target = xCoordinate[location] - selfx;
    int y_target = yCoordinate[location] - selfy;
    // decide the direction
    action = direction(x_target, y_target);

    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

================================= 2021 / 03 / 23
#include "agent_dll.h"
#include<bits/stdc++.h>
using namespace std;
const size_t NUM_ACTIONS = 9;
enum actions { NOOP = 0, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

#ifdef __cplusplus
extern "C"
{
#endif

int direction(int x_target, int y_target)
{
    int action;
    if(x_target == 0 && y_target > 0) //the target ball is above
        action = DOWN;
    else if(x_target == 0 && y_target < 0) //the target ball is under
        action = UP;
    else if(x_target > 0 && y_target == 0) //the target ball is on the right
        action = RIGHT;
    else if(x_target < 0 && y_target == 0) //the target ball is on the left
        action = LEFT;
    else if(x_target > 0 && y_target > 0) //the target ball is at the bottom right
        action = DOWN_RIGHT;
    else if(x_target > 0 && y_target < 0) //the target ball is at the top right
        action = UP_RIGHT;
    else if(x_target < 0 && y_target > 0) //the target ball is at the bottom left
        action = DOWN_LEFT;
    else if(x_target < 0 && y_target < 0) //the target ball is at the up right
        action = UP_LEFT;

    return action;
}
__declspec(dllexport) void controller(int &action, const size_t agent, const size_t num_agents, const size_t num_resources, const int* circleRadius,
                                      const int* xCoordinate, const int* yCoordinate, const int* xVelocity, const int* yVelocity) // the coordinates of  balls and resource centers are in turn placed in the array xCoordinate, and yCoordinate
{
    freopen("log.txt", "a+", stdout);
    int selfx = xCoordinate[0]; //ball 1's xCoordinate
    int selfy = yCoordinate[0]; //ball 1's yCoordinate
    int location = 10; //first black ball's location
    bool flag = false;
    int maximum_blackball = 5; //assume the biggest black ball that ball 1 need to catch
    int min_distance = 800;
    // find the biggest black ball and the closest, return its location

    if ((xCoordinate[0] - circleRadius[0] > 200) &&  (xCoordinate[0] + circleRadius[0] < 1200) && (yCoordinate[0] - circleRadius[0] > 200) &&  (yCoordinate[0] + circleRadius[0] < 400))
    {
        cout << "x = " << xCoordinate[0] - circleRadius[0] << " " << "y = " << yCoordinate[0] - circleRadius[0] << " " << endl;
        for(size_t i = 10; i < 15; i++){
            int x_distance = (xCoordinate[i] - xCoordinate[0]) * (xCoordinate[i] - xCoordinate[0]);
            int y_distance = (yCoordinate[i] - yCoordinate[0]) * (yCoordinate[i] - yCoordinate[0]);
            int two_distance = sqrt(x_distance + y_distance);
            if(circleRadius[i] > 0 && circleRadius[i] >= maximum_blackball && two_distance < min_distance ){
                maximum_blackball = circleRadius[i];
                min_distance = two_distance;
                location = i;
                flag = true;
            }
        }
    }
    int maximum_ball = 0;
    int mini_distance = 1600;
    // if the black ball's radius are all smaller than 5, and the target turn to the ball which is smaller than ball 1 and the biggest in ball 2 to ball 10;
    if(!flag){

        if ((xCoordinate[0] - circleRadius[0] > 200) &&  (xCoordinate[0] + circleRadius[0] < 1200) && (yCoordinate[0] - circleRadius[0] > 200) &&  (yCoordinate[0] + circleRadius[0] < 400))
        {
            cout << "x = " << xCoordinate[0] - circleRadius[0] << " " << "y = " << yCoordinate[0] - circleRadius[0] << " " << endl;
            for(size_t i = 10; i < 15; i++){
                if(circleRadius[i] < 5){
                    int x_distance = (xCoordinate[i] - xCoordinate[0]) * (xCoordinate[i] - xCoordinate[0]);
                    int y_distance = (yCoordinate[i] - yCoordinate[0]) * (yCoordinate[i] - yCoordinate[0]);
                    int two_distance = sqrt(x_distance + y_distance);
                    for(size_t t = 1; t < 10; t++){
                        if(circleRadius[t] < circleRadius[0] && circleRadius[t] > 0 && circleRadius[t] > maximum_ball && two_distance < mini_distance ){
                            maximum_ball = circleRadius[t];
                            min_distance = two_distance;
                            location = t;
                            break;
                        }
                    }
                }
            }
        }
    }

    // find the target in the which side of ball 1
    int x_target = xCoordinate[location] - selfx;
    int y_target = yCoordinate[location] - selfy;
    // decide the direction
    action = direction(x_target, y_target);
    fclose(stdout);
    return;
}

#ifdef __cplusplus
}
#endif

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
=====================================================================================