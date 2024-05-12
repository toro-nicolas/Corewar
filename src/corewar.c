/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** The file containing the corewar functions
*/
/**
 * @file corewar_init.c
 * @brief The file containing the corewar functions
 */

#include "../include/corewar.h"

/**
 * @brief Get the corewar structure
 * @return <b>corewar_t*</b> The corewar structure
 */
corewar_t *get_corewar(void)
{
    static corewar_t corewar = {0};

    return &corewar;
}

/**
 * @brief Free the corewar structure and all the memory allocated
 * @return <b>void</b>
 */
void free_corewar(void)
{
    corewar_t *corewar = get_corewar();

    if (corewar == NULL)
        return;
    my_free();
}

/**
 * @brief The virtual machine of the corewar
 * @return <b>int</b> <u>0</u> if the corewar is running, <u>84</u> otherwise
 */
int corewar(void)
{
    corewar_t *corewar = get_corewar();

    if (corewar == NULL)
        return 84;
    return 0;
}
