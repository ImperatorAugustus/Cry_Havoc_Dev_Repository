; thank you RobZ!
{if component "engine"
    {damage_report "hit_engine" "component/hit_engine"}
}
(define "body_damage_display"
    {if hit_side front
        {damage_report "hit_hull_front" "component/hit_hull_front"}
    else hit_side back
        {damage_report "hit_hull_rear" "component/hit_hull_rear"}
    else hit_side left
        {damage_report "hit_hull_left" "component/hit_hull_left"}
    else hit_side right
        {damage_report "hit_hull_right" "component/hit_hull_right"}
    else hit_side top
        {damage_report "hit_hull_top" "component/hit_hull_top"}
    else
        {damage_report "hit_hull" "component/hit_hull"}
    }
)
{if volume "body"
    ("body_damage_display")
}
{if volume "body1"
    ("body_damage_display")
}
{if volume "body2"
    ("body_damage_display")
}
{if volume "body3"
    ("body_damage_display")
}
{if volume "body4"
    ("body_damage_display")
}
{if volume "body5"
    ("body_damage_display")
}
{if volume "body6"
    ("body_damage_display")
}
{if volume "body7"
    ("body_damage_display")
}
{if volume "body8"
    ("body_damage_display")
}
{if volume "body9"
    ("body_damage_display")
}

(define "turret_damage_display"
    {if component "turret"
        {if hit_side front
            {damage_report "hit_turret_front" "component/hit_turret_front"}
        else hit_side back
            {damage_report "hit_turret_rear" "component/hit_turret_rear"}
        else hit_side left
            {damage_report "hit_turret_left" "component/hit_turret_left"}
        else hit_side right
            {damage_report "hit_turret_right" "component/hit_turret_right"}
        else hit_side top
            {damage_report "hit_turret_top" "component/hit_turret_top"}
        else
            {damage_report "hit_turret" "component/hit_turret"}
        }
    }
)

{if volume "turret"
    ("turret_damage_display")
}
{if volume "turret1"
    ("turret_damage_display")
}
{if volume "turret2"
    ("turret_damage_display")
}
{if volume "turret3"
    ("turret_damage_display")
}
{if volume "turret4"
    ("turret_damage_display")
}
{if volume "turret5"
    ("turret_damage_display")
}
{if volume "turret6"
    ("turret_damage_display")
}
{if volume "turret7"
    ("turret_damage_display")
}
{if volume "mantlet"
    {damage_report "hit_mantlet" "component/hit_mantlet"}
}
{if volume "mantlet1"
    {damage_report "hit_mantlet" "component/hit_mantlet"}
}
{if volume "mantlet2"
    {damage_report "hit_mantlet" "component/hit_mantlet"}
}
{if volume "mantled"
    {damage_report "hit_mantlet" "component/hit_mantlet"}
}
{if component "gun"
    {damage_report "hit_gun" "component/hit_gun"}
}
{if volume "barrel"
    {damage_report "hit_gun" "component/hit_gun"}
}
{if volume "breech"
    {damage_report "hit_gun" "component/hit_breech"}
}
{if volume "cupola"
    {damage_report "hit_cupola" "component/hit_cupola"}
}
{if volume "mg_port"
    {damage_report "hit_mg_port" "component/hit_mg_port"}
}
{if component "trackleft"
    {damage_report "hit_trackleft" "component/hit_trackleft"}
}
{if component "trackright"
    {damage_report "hit_trackright" "component/hit_trackright"}
}
{if component "shield"
    {damage_report "hit_shield" "component/hit_shield"}
}
{if component "armor_hull"
    {damage_report "hit_shield" "component/hit_hull_front"}
}
{if component "armor_turret"
    {damage_report "hit_shield" "component/hit_mantlet"}
}
{if volume "shieldr1" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr2" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr3" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr4" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr5" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr6" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr7" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr8" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldr9" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl1" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl2" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl3" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl4" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl5" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl6" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl7" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl8" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldl9" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield1"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield2"  {damage_report "hit_shield" "component/hit_shield"}}  
{if volume "shield3"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield4"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield5"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield6"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield7"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield8"  {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shield9"  {damage_report "hit_shield" "component/hit_shield"}}

{if volume "shieldw1" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldw2" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldw3" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldw4" {damage_report "hit_shield" "component/hit_shield"}}
{if volume "shieldw5" {damage_report "hit_shield" "component/hit_shield"}}