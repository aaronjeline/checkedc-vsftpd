#ifndef VSFTP_HASH_H
#define VSFTP_HASH_H

struct hash;

typedef unsigned int (*hashfunc_t)(unsigned int, void*);

struct hash *hash_alloc(unsigned int buckets, unsigned int key_size, unsigned int value_size, hashfunc_t hash_func : itype(_Ptr<unsigned int(unsigned int, _Ptr<void>)>)) : itype(_Ptr<struct hash>);
void* hash_lookup_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key : itype(_Ptr<void>)) : itype(_Ptr<void>);
void hash_add_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key : itype(_Ptr<void>), void* p_value : itype(_Ptr<void>));
void hash_free_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key : itype(_Ptr<void>));

#endif /* VSFTP_HASH_H */

