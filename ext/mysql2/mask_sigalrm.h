#ifndef MYSQL2_MASK_SIGALRM_H
#define MYSQL2_MASK_SIGALRM_H

#include <signal.h>
#include <pthread.h>

#define MASK_SIGALRM \
  sigset_t sigalrm_set; \
  sigaddset(&sigalrm_set, SIGALRM); \
  pthread_sigmask(SIG_BLOCK, &sigalrm_set, NULL);

#define UNMASK_SIGALRM \
  pthread_sigmask(SIG_UNBLOCK, &sigalrm_set, NULL);

#endif
