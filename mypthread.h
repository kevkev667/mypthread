#ifndef H_MYPTHREAD
#define H_MYPTHREAD
#include<ucontext.h>
// Types
typedef struct {
	unsigned long int tid;
	char ready;
	ucontext_t* context;
	unsigned long long waitingon;
	void * retval;
} mypthread;


struct Qnode
{
	mypthread * thread;
	struct Qnode * next;
};

struct Wnode
{
	mypthread * thread;
	struct Wnode * next;

};

typedef unsigned long int mypthread_t;

typedef struct {
	char detachstate;
} mypthread_attr_t;

// Functions
void removet(ucontext_t * target, void * retval);

void enqueue(mypthread * thread);

mypthread * dqueue();

int mypthread_create(mypthread_t *thread, const mypthread_attr_t *attr,
			void *(*start_routine) (void *), void *arg);

void mypthread_exit(void *retval);

int mypthread_yield(void);

int mypthread_join(mypthread_t thread, void **retval);


/* Don't touch anything after this line.
 *
 * This is included just to make the mtsort.c program compatible
 * with both your ULT implementation as well as the system pthreads
 * implementation. The key idea is that mutexes are essentially
 * useless in a cooperative implementation, but are necessary in
 * a preemptive implementation.
 */

typedef int mypthread_mutex_t;
typedef int mypthread_mutexattr_t;

static inline int mypthread_mutex_init(mypthread_mutex_t *mutex,
			const mypthread_mutexattr_t *attr) { return 0; }

static inline int mypthread_mutex_destroy(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_lock(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_trylock(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_unlock(mypthread_mutex_t *mutex) { return 0; }

#endif
