// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

int count = 0;
bool loaded = false;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000000;

// Hash table
node *table[N] = {NULL};

//--------------------------------------------------ZOB HASH-----------------------------------------------------
// Zobhash rotate function
unsigned int RotateLeft(unsigned int value, int countzob)
{
	int r = countzob % 32;
	return (value << r) | (value >> (32 - r));
}

unsigned int RandomNumbers[] = {
            0x5D60D139,
            0x464D952B,
            0x59D0ABFD,
            0x7552995C,
            0x4403A21F,
            0x5F2D890C,
            0x2E52372B,
            0x292614BF,
            0x650A2FAC,
            0x2AE32EC8,
            0x10B46261,
            0x3173E4B7,
            0x157675BA,
            0x29BC961C,
            0x5D2E9DB6,
            0x368F7F24,
            0x398340A8,
            0x57F22CAE,
            0x74F547CE,
            0x3CDD3EB4,
            0x2235E2BF,
            0x61F6D2C1,
            0x1B2921BF,
            0x3C981448,
            0x177EFA9B,
            0x14029CA8,
            0x2F5E4B1A,
            0x56846712,
            0x66C34128,
            0x19B60BB1,
            0x43EC9A97,
            0x463915C7,
            0x7C12A8B4,
            0x2D3441C0,
            0xECF4E49,
            0x28B6A932,
            0x34954E39,
            0x95AF2BD,
            0x40DEDFD9,
            0x38DAA522,
            0x5C98E835,
            0x31BF45F7,
            0x20ED4335,
            0x447ACDED,
            0x78A5958D,
            0x7A3E0D2F,
            0xE384DFE,
            0x5D8E6F28,
            0x2EC9FBFF,
            0x49510F4B,
            0xD6B1EED,
            0x23C20008,
            0x36896ABC,
            0xA0225E,
            0x14C77C0B,
            0x7019FC4C,
            0x42EFCAA4,
            0x4FEF8081,
            0x5DD39EC1,
            0x30010577,
            0x2FCF3DF2,
            0x57CDD018,
            0x4262D396,
            0x4B5423FB,
            0x66F69430,
            0x4A7B4C99,
            0x35613C02,
            0x684233F9,
            0x1AED47D3,
            0x3477F484,
            0x1FA30EB,
            0x30284DEB,
            0x17134CD5,
            0x3C1AA2AC,
            0x6044567E,
            0x70769CC7,
            0x41098F8C,
            0x56AE53D1,
            0x43F27EBA,
            0x1D40ED6B,
            0x5CA4EAA,
            0x51CFDBF1,
            0x594D720E,
            0x21AF5318,
            0x502E19D8,
            0x137D2F1C,
            0x6A5F0B60,
            0x659414A3,
            0x2133A705,
            0x13654FD1,
            0x7D9235C5,
            0x175CB684,
            0x2B8753FB,
            0x10DDDA62,
            0x90B6730,
            0x4CB181D,
            0x6F5C7260,
            0x55991F39,
            0x5D8439BC,
            0x2E2A48F4,
            0x44DCD12D,
            0x25F61A04,
            0x42A12755,
            0x48BF007F,
            0x4319BD25,
            0x195FA3ED,
            0x195C1EA6,
            0x1FBF67BA,
            0x363A3D92,
            0x1B89FDF3,
            0x3A606EEB,
            0x54761F9A,
            0x594618FA,
            0x4092B156,
            0x2A36B6CD,
            0x5DFF6200,
            0x7E805E09,
            0x20B3807E,
            0x7B260A22,
            0x53796514,
            0x601C4138,
            0x4FCD275E,
            0x470E8CF4,
            0x787F802,
            0x36E5BEBE,
            0x6A9D7A66,
            0x4A0F9F0,
            0x6357273,
            0x330F3B7C,
            0x5B793E61,
            0x11A2A67,
            0x6B707052,
            0x792A1A14,
            0x15C835C6,
            0x58641C3D,
            0x5FD434A5,
            0xF2EB49C,
            0x108E718F,
            0x5E9595F2,
            0x36CE75EB,
            0x7A211075,
            0x4A9FA3A6,
            0x2F59D711,
            0x5A9A912,
            0x5904E0E5,
            0x291C162B,
            0x3E169D89,
            0x6AF4A2A4,
            0x66A72394,
            0x2B0C052F,
            0x64ABA13,
            0x4EA8F1E2,
            0x5A731516,
            0xA0AD4A8,
            0x4E0E07BB,
            0x750FA9CE,
            0x5EE78D0F,
            0x3B192F53,
            0x11D941C1,
            0x587C42BE,
            0x14BEA9FD,
            0x1326AC33,
            0x6CB02C3D,
            0x5AC0FF30,
            0x1A6FD38C,
            0x4EEFFE98,
            0x5B4C0585,
            0x437DE334,
            0x682E9518,
            0x4A628227,
            0x4ED0AD64,
            0x6DF1EC7A,
            0x421DEA8B,
            0x44579437,
            0x5958549E,
            0x157C9D92,
            0x2073504D,
            0x4164E3E2,
            0x2E83171C,
            0xDC9A893,
            0x2C86DCDD,
            0x19AC574B,
            0x1F8E4EDE,
            0x803364D,
            0x552E844E,
            0x32713884,
            0x10FD5B3C,
            0x6F1F456C,
            0x47BA2E0A,
            0x6354726E,
            0xECA796,
            0x54158548,
            0x7EB52FCD,
            0x6195334,
            0x220FCBEE,
            0x66FA6442,
            0x5DEF7768,
            0x5498D7E0,
            0x6B39D585,
            0xA14E24D,
            0x4DD010A5,
            0x7A98BA54,
            0x2C60D8C,
            0x1C44A16D,
            0x5C3B57CA,
            0x1858CD98,
            0xC8B0757,
            0x161B80DF,
            0x30B28009,
            0x38916A29,
            0x549C5981,
            0x1D82A92D,
            0xC961837,
            0x40F992E,
            0x2BF565E1,
            0x7B1252B1,
            0x73985D54,
            0x64ACF5F0,
            0x5927AE2,
            0x67FE9B07,
            0x3DF2A35C,
            0x6C2CC018,
            0x7BC3B529,
            0x4DA22AA,
            0x4975DA91,
            0x7ABB281B,
            0x6F3CBCAC,
            0x3C049757,
            0x2247C849,
            0x725DF05B,
            0x378D2629,
            0x4BDA786C,
            0x562B0E5C,
            0x246E34CF,
            0x3FF997ED,
            0x31EE2288,
            0x16E649BF,
            0x349AD71,
            0x2BC7DE82,
            0x3CD5B6B6,
            0x25E6312D,
            0x7AE1DA5C,
            0x3E6CC563,
            0xF28C3E1,
            0xEB818ED,
            0x6369FE68,
            0x477F6D11,
            0x7AA5969F,
            0x5A23ED52,
            0x26FD793C,
            0x736206ED,
            0x79428177,
            0x4F065CFE,
            0x33B3A7E,
            0x4C223EF0,
            0x61A3508C
        };

unsigned long RandomStart = 0x7ED5052A;
//-----------------------------------------------------ZOB HASH-----------------------------------------------------

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hash_index = hash(word);

    if (table[hash_index] == NULL)
    {
        return false;
    }
    else
    {
        node *trav = table[hash_index];
        while (trav != NULL)
        {
            if (!strcasecmp(trav->word, word))
            {
                return true;
                break;
            }
            trav = trav->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int leng = strlen(word);
    unsigned int hash = RandomStart;
	for(int i = 0; i < leng; i++)
		hash ^= RotateLeft(RandomNumbers[(int)tolower(word[i])], i + 1);
	return hash % N;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dfile = fopen(dictionary, "r");
    if (dfile == NULL)
    {
        return false;
    }

    while (1)
    {
        char word[LENGTH + 1];

        fscanf(dfile, "%s", word);

        int hash_index = hash(word);

        if (table[hash_index] == NULL)
        {
            table[hash_index] = malloc(sizeof(node));
            strcpy(table[hash_index]->word, word);
            table[hash_index]->next = NULL;
        }
        else if (table[hash_index] != NULL)
        {
            node *tmp = table[hash_index]->next;
            table[hash_index]->next = malloc(sizeof(node));
            table[hash_index]->next->next = tmp;
            strcpy(table[hash_index]->next->word, word);
        }
        count++;

        if (feof(dfile))
        {
            break;
        }
    }
    fclose(dfile);
    loaded = true;
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return count - 1;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *trav = table[i];
            do
            {
                node *tmp = trav;
                trav = trav->next;
                free(tmp);
            }
            while (trav != NULL);
        }
    }
    return true;
}

