
mysql_data_stream_t * mysql_data_stream_init(int, mysql_session_t *);
void mysql_data_stream_close(mysql_data_stream_t *);

char *user_password(char *);

inline int mysql_pkt_get_size(pkt *);
inline enum MySQL_response_type mysql_response(pkt *);


gboolean query_is_cachable(mysql_session_t *, const char *, int);

typedef struct _rand_struct_t {
  unsigned long seed1,seed2,max_value;
  double max_value_dbl;
} rand_struct_t;

void create_ok_packet(pkt *, unsigned int);
void create_handshake_packet(pkt *, char *);
int check_client_authentication_packet(pkt *, mysql_session_t *);
void create_err_packet(pkt *, unsigned int , uint16_t,char *);
int authenticate_mysql_client(mysql_session_t *);
void authenticate_mysql_client_send_OK(mysql_session_t *);
void authenticate_mysql_client_send_ERR(mysql_session_t *, uint16_t , char *);
int mysql_check_alive_and_read_only(const char *, uint16_t);
void proxy_create_random_string(char *, uint , struct rand_struct *);
inline double proxy_my_rnd(struct rand_struct *);
void proxy_scramble(char *, const char *, const char *);
void proxy_compute_sha1_hash_multi(uint8 *, const char *, int , const char *, int);
inline void proxy_compute_two_stage_sha1_hash(const char *, size_t, uint8 *, uint8 *);
void proxy_compute_sha1_hash(uint8 *, const char *, int);
void proxy_my_crypt(char *, const uchar *, const uchar *, uint);
