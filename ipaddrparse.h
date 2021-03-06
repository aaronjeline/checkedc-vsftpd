#ifndef VSF_IPADDRPARSE_H
#define VSF_IPADDRPARSE_H

struct mystr;

/* Effectively doing the same sort of job as inet_pton. Since inet_pton does
 * a non-trivial amount of parsing, we'll do it ourselves for maximum security
 * and safety.
 */

#include <netinet/in.h>

const unsigned char *vsf_sysutil_parse_ipv6(const struct mystr *p_str : itype(_Ptr<const struct mystr>)) : itype(_Array_ptr<const unsigned char>) count(sizeof(struct in6_addr));

const unsigned char *vsf_sysutil_parse_ipv4(const struct mystr *p_str : itype(_Ptr<const struct mystr>)) : itype(_Array_ptr<const unsigned char>) count(sizeof(struct in_addr));

const unsigned char *vsf_sysutil_parse_uchar_string_sep(const struct mystr *p_str : itype(_Ptr<const struct mystr>), char sep, unsigned char *p_items : itype(_Array_ptr<unsigned char>) count(items), unsigned int items) : itype(_Array_ptr<const unsigned char>) count(items);

#endif /* VSF_IPADDRPARSE_H */

