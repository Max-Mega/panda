/******************************************************************************
  Windows.c

  Change Control:                                                      DDMMYYYY
    Michael Still    File created                                      22062001
	Michael Still    Complete change of purpose -- now windows db      22022002

  Purpose:
    This file implements a _very_ simple database to replace TDB on Windows.
	It doesn't have much future -- I would much rather port TDB to Windows when
	I have the time. I would love patches which do that. The other thing I
	wouldn't mind is some simple patches to make this run faster (it is very
	bloody minded at the moment).

  Copyright (C) Michael Still 2000 - 2002

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
******************************************************************************/

#include "stdafx.h"

{
  
   
   
 
 

panda_windbopen (panda_pdf * document) 
{
  
  
  
  
  
    


panda_windbclose (panda_pdf * document) 
{
  
  
  
    
    {
      
      
      
      
      
    
  


panda_windbwrite (panda_pdf * document, char *key, char *value) 
{
  
  
    // Find the item, or the end -- I have to do it this way so that Visual Studio doesn't
    // complain
    now = (panda_windb *) document->db;
  
    
    {
      
	
      
    
  
    // We are appending to the chain
    if (now->next == NULL)
    
    {
      
      
      
      
      
      
      
    
  
    // We are overwriting an existing value (a memory leak for the moment)
    now->value = panda_xsnprintf ("%s", value);


panda_windbread (panda_pdf * document, char *key) 
{
  
  
    // Find the item, or the end
    now = (panda_windb *) document->db;
  
    
    {
      
	
      
    
  
    // now->next = NULL means at the end of the list
    return (now->next == NULL) ? NULL : panda_xsnprintf ("%s", now->value);
