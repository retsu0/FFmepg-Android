/***************************************************************************/
/*                                                                         */
/*  ftsnames.h                                                             */
/*                                                                         */
/*    Simple interface to access SFNT name tables (which are used          */
/*    to hold font names, copyright info, notices, etc.) (specification).  */
/*                                                                         */
/*    This is _not_ used to retrieve glyph names!                          */
/*                                                                         */
/*  Copyright 1996-2003, 2006, 2009, 2010, 2013 by                         */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


#ifndef __FT_SFNT_NAMES_H__
#define __FT_SFNT_NAMES_H__


#include <ft2build.h>
#include FT_FREETYPE_H

#ifdef FREETYPE_H
#error "freetype.h of FreeType 1 has been loaded!"
#error "Please fix the directory search order for header files"
#error "so that freetype.h of FreeType 2 is found first."
#endif


FT_BEGIN_HEADER


  /*************************************************************************/
  /*                                                                       */
  /* <Section>                                                             */
  /*    sfnt_names                                                         */
  /*                                                                       */
  /* <Title>                                                               */
  /*    SFNT Names                                                         */
  /*                                                                       */
  /* <Abstract>                                                            */
  /*    Access the names embedded in TrueType and OpenType files.          */
  /*                                                                       */
  /* <Description>                                                         */
  /*    The TrueType and OpenType specifications allow the inclusion of    */
  /*    a special `names table' in font files.  This table contains        */
  /*    textual (and internationalized) information regarding the font,    */
  /*    like family name, copyright, version, etc.                         */
  /*                                                                       */
  /*    The definitions below are used to access them if available.        */
  /*                                                                       */
  /*    Note that this has nothing to do with glyph names!                 */
  /*                                                                       */
  /*************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    FT_SfntName                                                        */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A structure used to model an SFNT `name' table entry.              */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    platform_id :: The platform ID for `string'.                       */
  /*                                                                       */
  /*    encoding_id :: The encoding ID for `string'.                       */
  /*                                                                       */
  /*    language_id :: The language ID for `string'.                       */
  /*                                                                       */
  /*    name_id     :: An identifier for `string'.                         */
  /*                                                                       */
  /*    string      :: The `name' string.  Note that its format differs    */
  /*                   depending on the (platform,encoding) pair.  It can  */
  /*                   be a Pascal String, a UTF-16 one, etc.              */
  /*                                                                       */
  /*                   Generally speaking, the string is not               */
  /*                   zero-terminated.  Please refer to the TrueType      */
  /*                   specification for details.                          */
  /*                                                                       */
  /*    string_len  :: The length of `string' in bytes.                    */
  /*                                                                       */
  /* <Note>                                                                */
  /*    Possible values for `platform_id', `encoding_id', `language_id',   */
  /*    and `name_id' are given in the file `ttnameid.h'.  For details     */
  /*    please refer to the TrueType or OpenType specification.            */
  /*                                                                       */
  /*    See also @TT_PLATFORM_XXX, @TT_APPLE_ID_XXX, @TT_MAC_ID_XXX,       */
  /*    @TT_ISO_ID_XXX, and @TT_MS_ID_XXX.                                 */
  /*                                                                       */
  typedef struct  FT_SfntName_
  {
    FT_UShort  platform_id;
    FT_UShort  encoding_id;
    FT_UShort  language_id;
    FT_UShort  name_id;

    FT_Byte*   string;      /* this string is *not* null-terminated! */
    FT_UInt    string_len;  /* in bytes */

  } FT_SfntName;


  /*************************************************************************/
  /*                                                                       */
  /* <Function>                                                            */
  /*    FT_Get_Sfnt_Name_Count                                             */
  /*                                                                       */
  /* <Description>                                                         */
  /*    Retrieve the number of name strings in the SFNT `name' table.      */
  /*                                                                       */
  /* <Input>                                                               */
  /*    face :: A handle to the source face.                               */
  /*                                                                       */
  /* <Return>                                                              */
  /*    The number of strings in the `name' table.                         */
  /*                                                                       */
  FT_EXPORT( FT_UInt )
  FT_Get_Sfnt_Name_Count( FT_Face  face );


  /*************************************************************************/
  /*                                                                       */
  /* <Function>                                                            */
  /*    FT_Get_Sfnt_Name                                                   */
  /*                                                                       */
  /* <Description>                                                         */
  /*    Retrieve a string of thyk…Pû3
İfÙg² I†û—=QSj\•]šÙÑÇ&@´ àİ*¢Ú›³¦ŸOÒ(ª¬u²ªv†î(o€Î®>¦c&„!¸vWà_û—Ù¢˜4‹³@lª_¼œxøuñš/›Ò†R³ÔÉsn–$h²áş+t*!ßH•	²XITì£p›‡ÍÌqÌG™Órú<ê;pç /†ÿ@Gj÷#ğ¿àX
A\fFãoí0ì`•¤‚ì…ØÁÕßY„Ÿ«LBÑõ¯ÃD^0ñ¤yi):FÕœš•k\"ï±
Ns—ÂdjÆƒ!ÒÂŸ­àüZ-È®²d`s^h1x‡+°TM^‡ç}ÁEë¨V}0Š“(hÊôY# Û§Ãò¶X¡YF”°; :â”+je¥ï“	d{bæM[¦*bÄ¦.FÜL<ClzAé¥Js&ú°ùT6°_Èuœ´CÃ]_2TçÃWôOÖ¾…ğœ=*–óÊ•©š±S*À#'Ù¨(F§¢‚0®ü‹l1óÄ‡êètşL²‰°9Ş@Ôw'z¬††:¡Ì?  q¾€ëó¦³`°<}p1ˆ&èyš‹«8}eOâşPjmäSÓø6ŞbI+5sÏlôÑıìzª]+Ò
}LÂ‚gDğ–b@FvñênmÎ5>wªd$Şã½^v¥ÏqPZÏähüO1ÿ÷‹¿«.0)‰†$Cb¡ôa¸«Uïç
w˜šl1‡%iq(î3N÷L›Ùfd·l·í—§I-Óë¯ÌŸÄşƒí}ø¤Y}ˆdÀ&/"¯äÁ„j£¾ÃGşB0U`‡¶ıuÓÍ­4pchW ˜lb½xL*æ…òÀMkİWfİÛ®îêÿlş§
…øó&uç;”~¾9Â[WoÁU¥í!ä³¶Ì`jüY,®ºû–üiÃ[w%t°È´>ù"tã§ É¤Ùi°0ª’§’Ásv3I§lDR ØÜ15!½göÏ<¿ä;ş¤X}µ[ú¸HL¢‚}*oğ­2î<Z|”ÄDòù‹è?¬#[èO>è§@Ø!ØåŠdÈ€õ)	:¦ÿïWêpôRˆ²Óä%¶ÔğI!Wî`¢è,WZÌö‹equKÏ)Ty¹ á•ÿX¾Ë%æ·4¯ì(bfÓ¹F|¨ùÏ¶¹ÿâ¶D4:¤’P™P23™?h€ˆ2ôk”­¶~¯£Úá®¹6œFPš«¶|ÛªîZkãÏ¯¸xƒİµU6ÕŒˆĞCfç9MÓ¬ıÃ»f²ìQĞ9ÒöR(kl¯sÓÕJì–y|\J Fá¹g3Ñô&Ê]Š§4v§êYP>C—è¸ıÄaÜ©.U˜Ha®˜½±á¬3¹õ})¶_IXsB¼å§4YÀ3Ëı¼¢1ÅÃ…?ÖÀ´/,ß|V"´ËĞé³Ì¹±TçnûSéÜü4wH¾íùĞØ/­¡?óŒKh‚Ójæ¿Cš·Ÿ}¬Yå±ìL.†_Ö*´ ˆkzÊHÆ«m‰ÄDË|Ÿªb¹E½	ğkl4€Q6zu¶!?Ãû…É  §·&ÿUûÖiW&<@Hfç„ãş}ûÒy‡ˆä¶½ÿŸ§×¸}ÀïÀÜÍ#ıõ¾\vÓ“ò·H	ŸQšE˜¥­Ëº-ö®“Eî®¼ªÃ6ã¨™Ğòóş,P»ó:¦·:h™5^ëÿíxñøÓ›^>5Zcqš,»vè™k¨#(ïîğcÒ%¡uZùi“Oeñ¿  [ı”Ê)á¹“ÿ9ûİQ,Å›r“¡ÏJ/SÀVç¯¦"cšÊ§Ş=™N¢-ÒtN w¬ì£PT˜åêb¥È¸Û2ÒÎb`ô	Î7š¤;Wñ}6Hkm8Çš,öşGËvî b1sÎ[ ¯ƒ<ŒªNFÄî.Ì°_İvüKíãŠ³Çv~üúªWZÄëø6ÙAÄëã—ë¥sm ŸHsƒ÷>`iò“Ü3:3*’ï4äåfÁşqˆî:Áö`Ävo£b(k«ß¶Õ¤«Z¢‚Z™PkéØÌOúˆ+\Ìy  r'Ašª„Ô™Lÿk¹Oõ|Ç8AKº÷Œl~€záÆÀ„‚Ğ 75Í))('üCØÂ;w¦´d’pèüÔ˜k“½z`+Øå-]½ñeÊ•ÇT~‰«§ÃŞ8#PEœÕ@DŠqÚ PÄs²Õ
İ¾ÖVÇK¾f¼÷«Ğc%q†T=lKuÕ3¹ä·¨5=ÎxaÚ±2ZSÉæ$˜çL’^pi¹"¦ªÂÏ§#Ò-juŒ‰Z³h[¢kÇ.­ölŒ[¶!¬x9‘BYçr“3œŠûãä ËÆ];,i:Ä×E<1OÖ ÂÂbC÷wÀĞÓy6×mGåY}T_½Ô8j¼Øcp+™ 6ó¿6³IUjCi·¶¤Ü„‡3ªNjÈ4D%¿TA›Ê¯…^VËÖ1%èº³#îä‚PâĞNı%ìÓÊ°.ı„fš› 2³ƒùoX(û×f,S$òS{(%Š¼ë›ÅèËığ`e!;é(¿«{W‡»ïÌĞÒ./L¶+ó²½æNh²]o*—äÊ¯Ğd­l¤¡£J­¼"}Øz‚}ø°®Ùˆ#eœës}Õ	OÚ×xÚÆÅİ@Ó†³–E SC¼ˆï³îöZGäa’õñ~R¢)3Ş›;^°W§´u¯«ÖÉ£´"fò7ôPßh
LÃ÷ÿ
»ZRk7š‚›tâbQ(©s“_’³×@x©,fpŸp\…°JÅ7Ê7À=ÓÉï5z³Æ¤FÿSW:)Ók ‚¡úÂU¼¿b4ì=Ó‡'_@¾ Q¡Œır,È›NíTÚˆ Rø•nÖŸ|ş»fÉâsßëwšÏèÿ1}ÛjÔª¶ìæïÖò*DU}½GÂİ`â°‘ñ·L¢'(€D2LñşCî=J±š >²9nÚ6ÀZ\6e´×]/DIø‡îõğ¥‡qEaj¦ä€‹şşSƒù§=ÛÄô}6˜ şå‘³İöÏ$Õ4cb‘¢K1äTÕAÀ´:3'0¢—íK1¸ªw³ß”6\—T>ŸŞ ¦è* ª/Èûé	“TtP+¿ïÑr%šĞj†0Q½+WV§ıá—3ØØ—Å¬…
ÔÛ35¯¢Adçí/à-ÌĞ–ùÁbF¬Ù&®!J'Æ×îœ%G¬…­6}½ıî`'ºÈ)ˆ	¬,Q¿ W@}>wD^Î]<‡ÃP¼#Òé³aŸ ûhü8ıYv=Í&7M@£êÅÒZ 6ÊgÏßl·Ôæ¨%ãø³êUtT'GÈ ±nWcàùşåŞˆõ]!*®uàqÏºzº]:üJ´ÃˆŸç‡¹=iED‘‰Ãi9K2¡d‹Zà•=¾“¹Š‘‰±¿ö˜ˆë;šñpà„Y¸<âó‡M†i²†BUØŠhÉÇĞ”…C¦TãZç¯¯e–K?4+6Êl¥ÿÿÛ “‰å§œ‰é=£[ Ø–¦@,
vY’ëBúfIÔ½Æ‡æÒÑ@ƒo‹ïòf…{çÿƒÊ^¿s¢ä(ıXl¡lÂÿo] /2+¼{PR…ªR{v E<‹”ÆæQşI2w°í§ëé T•ÖÁÂ.;µfg‹ˆtbëDœk(E
)$˜×ÂÛn2ı|Rå·
ÓR}³Õ@1IÄòåëÌğ‚©l$-êÎmKğ‰%äsÿšzÕ§z¯IkšîûıøÛ7Øk@B<á„9;*=ÂYÿéGÑíe)3Ót÷uKª¹T}’C W—–Ê|à·“Cµ:°£\Üï¥]rS^zG‘1¯¬2