/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:05:35 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 10:53:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
		int _materiaCount;

	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &obj );
		MateriaSource &operator=(const MateriaSource &obj);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *m);
		virtual AMateria *createMateria(std::string const &type);
};
