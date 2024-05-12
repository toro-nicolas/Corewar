/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** The header of the corewar project
*/
/**
 * @file corewar.h
 * @brief The header of the corewar project
 */

#include "mymemory.h"
#include "myop.h"

#ifndef COREWAR_H_
    #define COREWAR_H_

// MACROS :



// STRUCTURES :

/**
 * @brief The cell structure
 * @note A cell is a memory case of the arena
 */
typedef struct cell_s {
    int address; // The address of the cell
    int value; // The value of the cell
    int owner; // The last champion who wrote in the cell
} cell_t;

/**
 * @brief The champion structure
 */
typedef struct champion_s {
    char *file_path; // The path of the file of the champion
    char *prog_name; // The program name
    char *comment; // The comment of the program
    int prog_size; // The program size
    int prog_number; // The program number
    int address; // The address of the program in the arena
    int reg[REG_NUMBER]; // The registers of the program
    int cycle; // The cycle of the program
    int live; // The live of the program
} champion_t;

/**
 * @brief The corewar structure
 */
typedef struct corewar_s {
    size_t total_cycle; // The total of cycle done
    int dump_cycle; // The cycle number to dump the memory
    node_t *champions; // The champions list
    node_t *arena; // The arena
} corewar_t;

/**
 * @brief Get the corewar object
 *
 * @return corewar_t*
 */
corewar_t *get_corewar(void);

/**
 * @brief Free the corewar structure
 *
 */
void free_corewar(void);



// FUNCTIONS PROTOTYPES :

    // Corewar functions :

/**
* @brief Get the corewar structure
* @return <b>corewar_t*</b> The corewar structure
*/
corewar_t *get_corewar(void);

/**
 * @brief Free the corewar structure and all the memory allocated
 * @return <b>void</b>
 */
void free_corewar(void);

/**
 * @brief The virtual machine of the corewar
 * @return <b>int</b> <u>0</u> if the corewar is running, <u>84</u> otherwise
 */
int corewar(void);


    // Parsing functions :

/**
* @brief Parse the arguments
* @param argc The number of arguments
* @param argv The arguments
* @return <b>int</b> <u>0</u> if the parsing is a success, <u>84</u> otherwise
*/
int parse_args(int argc, char **argv);


    // Champion functions :

/**
* @brief Get the next champion number disponible
* @return <b>int</b> The next champion number
*/
int get_next_champion_number(void);

/**
 * @brief Check if a champion number exist
 * @param number The champion number
 * @return <b>int</b> 1 if the champion number exist, 0 otherwise
 */
int champion_number_exist(int number);

/**
 * @brief Analyse each champion files and complete the champion structure
 * @return <b>int</b> <u>0</u> if the analyse is a success, <u>84</u> otherwise
 */
int analyse_champions(void);


    // Read files functions :

/**
 * @brief Read a file and return the content
 * @param filepath The file path
 * @param size The size of the bytes to read
 * @return <b>char*</b> The content of the file or NULL if an error occurred
 */
char *read_file(char *filepath, int size);


    // Header functions :

/**
 * @brief Get the program size
 * @param header The header of the program
 * @return <b>int</b> The program size
 */
int get_prog_size(char *header);

/**
 * @brief Check if the magic number is valid
 * @param header The header of the program
 * @return <b>int</b> 1 if the magic number is valid, 0 otherwise
 */
int is_valid_magic(char *header);

#endif /* COREWAR_H_ */
