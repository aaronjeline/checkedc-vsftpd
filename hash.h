#ifndef VSFTP_HASH_H
#define VSFTP_HASH_H

struct hash;

typedef _Ptr<unsigned int (unsigned int, void*)> hashfunc_t;

struct hash *hash_alloc(unsigned int buckets, unsigned int key_size, unsigned int value_size, hashfunc_t hash_func : itype(hashfunc_t )) : itype(_Ptr<struct hash>);
void* hash_lookup_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key);
void hash_add_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key, void* p_value);
void hash_free_entry(struct hash *p_hash : itype(_Ptr<struct hash>), void* p_key);

#endif /* VSFTP_HASH_H */

