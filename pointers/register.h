#ifndef REGISTER_H
#define REGISTER_H

typedef void(*FP_TYPE)(void);

void register_fn(FP_TYPE fp);
void call_registered_fns(void);

#endif  // REGISTER_H