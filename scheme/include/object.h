
/**
 * @file object.h
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 15 17:49:46 2012
 * @brief Object definition for SFS.
 *
 * Object definition for SFS.
 */

#ifndef _OBJECT_H_
#define _OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "number.h"


typedef struct object_t {

    uint type;

    union {

        num              number;
        char             character;
        string           string;
        string           symbol;
	struct object_t   *boolean; /* on rajoute la structure de type objet_t boolean comme dans la partie 1-6*/

        struct pair_t {
            struct object_t *car;
            struct object_t *cdr;
        }                pair;

        struct object_t *special; /*meme chose que empty_list ??*/

    } this;  /* this sert en c++ sera t-il mal interprete par le compilateur ?*/

} *object;


object make_object( uint type );
object make_nil( void ); /* fonction qui fait la meme chose que make empty list*/
object make_boolean( void ); /* ici on peut remplacer unsigned int par num */
object make_character(char c);
object make_pair(object p, object l);
object make_integer( int x );
object make_string(string st);
object make_symbol(string symbol);
object make_real( double x ) ;

#define SFS_NUMBER       0x00
#define SFS_CHARACTER    0x01
#define SFS_STRING       0x02
#define SFS_PAIR         0x03
#define SFS_NIL          0x04
#define SFS_BOOLEAN      0x05
#define SFS_SYMBOL       0x06


extern object nil;

#ifdef __cplusplus
}
#endif

#endif /* _OBJECT_H_ */
