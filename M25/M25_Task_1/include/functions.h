#ifndef M25_TASK_1_FUNCTIONS_H
#define M25_TASK_1_FUNCTIONS_H

#pragma once

struct dot
        {
            double coordinate_x, coordinate_y;
        };

void scalpel(dot &dot_1, dot &dot_2);

void hemostat(dot dot_tmp);

void tweezers(dot dot_tmp);

bool suture(dot &dot_1, dot &dot_2);


#endif //M25_TASK_1_FUNCTIONS_H
